import sys

# Define default file paths as constants
DEFAULT_FILE_PATHS = [
    "package_name/package.xml",
    "package_name/CMakeLists.txt",
    "package_name/include/package_name/package_name.hpp",
    "package_name/src/package_name.cpp",
    "package_name/src/package_name_node.cpp",
]

def replace_text_in_file(file_path, old_text, new_text):
    try:
        with open(file_path, 'r') as file:
            file_content = file.read()

        modified_content = file_content.replace(old_text, new_text)

        with open(file_path, 'w') as file:
            file.write(modified_content)

        print(f"Replacement complete in {file_path}")

    except FileNotFoundError:
        print(f"File not found: {file_path}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python replace_text.py <old_text> <new_text> [<file_path1> <file_path2> ...]")
        sys.exit(1)

    old_text = sys.argv[1]
    new_text = sys.argv[2]

    # Use default file paths if none are provided as command-line arguments
    file_paths = sys.argv[3:] if len(sys.argv) > 3 else DEFAULT_FILE_PATHS

    for file_path in file_paths:
        replace_text_in_file(file_path, old_text, new_text)

