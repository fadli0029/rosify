import os
import sys
import shutil

def rename_folders_and_files(root_dir, old_name, new_name):
    for root, dirs, files in os.walk(root_dir, topdown=False):
        for dir_name in dirs:
            old_dir_path = os.path.join(root, dir_name)
            new_dir_name = dir_name.replace(old_name, new_name)
            new_dir_path = os.path.join(root, new_dir_name)

            if old_dir_path != new_dir_path:
                os.rename(old_dir_path, new_dir_path)

        for file_name in files:
            old_file_path = os.path.join(root, file_name)
            new_file_name = file_name.replace(old_name, new_name)
            new_file_path = os.path.join(root, new_file_name)

            if old_file_path != new_file_path:
                os.rename(old_file_path, new_file_path)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python rename_files_and_folders.py <old_name> <new_name>")
        sys.exit(1)

    old_name = sys.argv[1]
    new_name = sys.argv[2]

    # Rename the root folder
    root_dir = os.getcwd()  # You can specify the root directory as needed
    new_root_dir = root_dir.replace(old_name, new_name)
    os.rename(root_dir, new_root_dir)

    # Recursively rename folders and files
    rename_folders_and_files(new_root_dir, old_name, new_name)

    print(f"Renaming complete from '{old_name}' to '{new_name}'")
