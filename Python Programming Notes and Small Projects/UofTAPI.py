import requests
import csv
import json

# === 1. COPY THESE FROM DEVTOOLS ===
URL = "https://api.easi.utoronto.ca/ttb/getPageableCourses"  # <- confirm from your cURL

HEADERS = {
    # copy ONLY the useful headers from "Copy as cURL"
    # Usually you want at least:
    "Accept": "application/json, text/plain, */*",
    "Content-Type": "application/json",
    # If the curl had other headers like "Authorization" or special tokens,
    # include them here as well.
    # Example:
    # "Authorization": "Bearer abcdef....",
}

# Base payload. Your request body in DevTools "Payload" tab should show something like:
# {
#   "campus":"STG",
#   "sessionCode":"20251",
#   "subjectCode":null,
#   "pageNumber":0,
#   "pageSize":50,
#   ...
# }
# Copy that shape here.
BASE_PAYLOAD = {
    "campus": "STG",          # example
    "sessionCode": "20251",   # example "Winter 2026" or similar
    "subjectCode": None,      # None means "all subjects", sometimes it's "", depends on API
    "searchText": None,
    "pageNumber": 0,
    "pageSize": 50            # bump this higher if allowed
    # include any other fields from the real payload (deliveryMode, division, level, etc)
}

# === 2. SCRAPE ALL PAGES ===
all_courses = []

while True:
    print(f"Fetching page {BASE_PAYLOAD['pageNumber']}...")
    resp = requests.post(URL, headers=HEADERS, json=BASE_PAYLOAD)
    resp.raise_for_status()

    data = resp.json()

    # You now need to inspect what key holds the actual course list.
    # Common patterns are like data["payload"]["pageableCourseResults"]
    # or data["courses"] etc.
    courses_this_page = data.get("payload", {}).get("pageableCourseResults", [])

    if not courses_this_page:
        break  # no more results -> stop

    all_courses.extend(courses_this_page)

    # increment pageNumber for next loop
    BASE_PAYLOAD["pageNumber"] += 1

print(f"Total courses collected: {len(all_courses)}")

# === 3. SAVE RAW JSON DUMP ===
with open("all_courses.json", "w") as f:
    json.dump(all_courses, f, indent=2)

# === 4. FLATTEN TO CSV ===
# You decide what columns you care about.
# Look at one course object to understand its fields.
# Example fields you might see:
# - code (like "CSC110Y1")
# - title
# - campus
# - instructors (array)
# - meetings (days/times/rooms)
# - enrollmentCap
# etc.

def flatten_course(course):
    """
    Turn each complex course dict into a flat row (strings only).
    You will customize this based on the actual JSON structure you see.
    We'll guess some common fields and join lists with ';'.
    """
    code = course.get("courseCode", "")
    title = course.get("courseTitle", "")
    campus = course.get("campus", "")
    term = course.get("session", "")
    # Example nested:
    instructors = []
    meetings = []

    for section in course.get("sections", []):
        # collect instructor names
        for inst in section.get("instructors", []):
            instructors.append(inst.get("name", ""))
        # collect meeting times
        mtg_days = section.get("meetingDays", "")
        mtg_start = section.get("startTime", "")
        mtg_end = section.get("endTime", "")
        mtg_loc = section.get("location", "")
        meetings.append(f"{mtg_days} {mtg_start}-{mtg_end} @ {mtg_loc}")

    return {
        "course_code": code,
        "title": title,
        "campus": campus,
        "term": term,
        "instructors": "; ".join(sorted(set(instructors))),
        "meetings": " | ".join(meetings),
    }

flat_rows = [flatten_course(c) for c in all_courses]

# figure out CSV columns from first row
fieldnames = list(flat_rows[0].keys()) if flat_rows else []

with open("all_courses.csv", "w", newline="") as f:
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(flat_rows)

print("Saved all_courses.json and all_courses.csv")