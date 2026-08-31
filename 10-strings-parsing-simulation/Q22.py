# Open and read the file safely
with open("names.txt", "r") as file:
    content = file.read().replace('"', '').split(",")

# Sort the names alphabetically
content.sort()

total_score = 0

# Calculate name scores
for placement, name in enumerate(content, start=1):
    score = sum(ord(char) - ord("A") + 1 for char in name)  # Sum letter values
    total_score += score * placement  # Multiply by position

print("Total name score:", total_score)
