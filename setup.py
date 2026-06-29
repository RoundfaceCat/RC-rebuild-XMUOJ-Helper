from setuptools import setup, find_packages

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setup(
    name="xmuojhelper",
    version="1.0.0",
    author="Duskydream & AI",
    description="A TUI tool for automated OJ submissions",
    long_description=long_description,
    long_description_content_type="text/markdown",
    packages=find_packages(),
    include_package_data=True,
    package_data={
        "xmuojhelper": ["prompt_instruction.md"],
    },
    install_requires=[
        "requests",
        "openai",
        "beautifulsoup4",
        "urllib3",
        "socksio",
        "httpx[socks]",
        "rich",
        "questionary"
    ],
    entry_points={
        "console_scripts": [
            "xmuoj=xmuojhelper.tui:main",
        ],
    },
    classifiers=[
        "Programming Language :: Python :: 3",
        "Operating System :: OS Independent",
    ],
    python_requires=">=3.7",
)
