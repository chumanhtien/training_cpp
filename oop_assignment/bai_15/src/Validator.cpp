#include "../inc/Validator.h"
#include <ctime>

// Kiểm tra tính hợp lệ của ngày sinh
void Validator::validateBirthday(const std::string& birthday) {
    // Kiểm tra định dạng và ký tự hợp lệ
    if (birthday.empty() || (birthday.find_first_not_of("0123456789-/") != std::string::npos)) {
        throw BirthDayException("Invalid birthday format! Only digits, '-' and '/' are allowed.");
    }

    // Thay thế '/' bằng '-' để đồng nhất
    std::string normalizedBirthday = birthday;
    std::replace(normalizedBirthday.begin(), normalizedBirthday.end(), '/', '-');

    // Kiểm tra định dạng ngày sinh
    std::stringstream ss(normalizedBirthday);
    std::string yearStr, monthStr, dayStr;

    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr);

    // Kiểm tra độ dài
    if (yearStr.length() > 4 || monthStr.length() > 2 || dayStr.length() > 2) {
        throw BirthDayException("Invalid birthday components length!");
    }

    // Chuyển đổi sang kiểu int
    int year = std::stoi(yearStr);
    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);

    // Lấy năm hiện tại
    time_t t = time(0);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;

    // Kiểm tra năm
    if (year <= 1900 || year > currentYear) {
        throw BirthDayException("Year must be greater than 1900 and less than current year.");
    }

    // Kiểm tra tháng
    if (month < 1 || month > 12) {
        throw BirthDayException("Month must be between 1 and 12.");
    }

    // Kiểm tra ngày hợp lệ theo tháng
    if (day < 1 || day > 31) {
        throw BirthDayException("Day must be between 1 and 31.");
    }

    // Kiểm tra số ngày hợp lệ trong tháng
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw BirthDayException("Invalid day for the given month.");
    }

    // Kiểm tra tháng 2
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2) {
        if (isLeapYear && day > 29) {
            throw BirthDayException("Invalid day for February in a leap year.");
        } else if (!isLeapYear && day > 28) {
            throw BirthDayException("Invalid day for February in a non-leap year.");
        }
    }  
}

// Kiểm tra tính hợp lệ của tên đầy đủ
void Validator::validateFullName(const std::string& fullName) {
    if (fullName.empty()) {
        throw FullNameException("Full name cannot be empty!");
    }

    // Kiểm tra xem tên có chứa ký tự không hợp lệ hay không
    std::regex nameRegex(R"(^[a-zA-Z\s]+$)");

    if (!std::regex_match(fullName, nameRegex)) {
        throw FullNameException("Full name can only contain letters and spaces!");
    }

    // Kiểm tra khoảng trắng ở đầu và cuối
    if (fullName.front() == ' ' || fullName.back() == ' ') {
        throw FullNameException("Full name cannot start or end with a space!");
    }

    // Kiểm tra khoảng trắng liên tiếp
    if (fullName.find("  ") != std::string::npos) {
        throw FullNameException("Full name cannot contain consecutive spaces!");
    }
}

void Validator::validateEnrollmentYear(const uint& enrollmentYear) {
    // Lấy năm hiện tại
    time_t t = time(0); // Lấy thời gian hiện tại
    struct tm* now = localtime(&t);
    uint currentYear = now->tm_year + 1900; // Chuyển đổi sang năm hiện tại

    // Kiểm tra năm có hợp lệ hay không
    if (enrollmentYear <= 0) {
        throw EncrollmentYearException("Encrollment year must be the positive integer number!");
    }

    if (enrollmentYear <= 1900) {
        throw EncrollmentYearException("Encrollment year must be more than 1900!");
    }

    if (enrollmentYear > currentYear) {
        throw EncrollmentYearException("Encrollment year must be less than current year!");
    }
}

void Validator::validateEntryScore(const double& entryScore) {
    // Check if the score is valid
    if (entryScore < 0.0 || entryScore > 10.0) {
        throw EntryCoreException("The entry score must be between 0.0 and 10.0!");
    }

}

void Validator::validateSemesterName(const std::string& semesterName) {
    // Get the current year
    time_t t = time(0);
    struct tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;

    // Regex to match the format abcd.y
    std::regex pattern(R"(^([1-9][0-9]{3})\.(1|2)$)");

    // Check if the format matches the regex
    std::smatch match;
    if (std::regex_match(semesterName, match, pattern)) {
        int year = std::stoi(match[1].str());

        // Validate the year part
        if (year <= 1900 || year >= currentYear) {
            throw SemesterNameException("The year in the semester name must be greater than 1900 and less than the current year.");
        }
    } else {
        throw SemesterNameException("Invalid semester name format. It should follow the format abcd.y, where y is either 1 or 2.");
    }
}