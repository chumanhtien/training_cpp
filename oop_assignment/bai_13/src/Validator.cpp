#include "../inc/Validator.h"

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

// Kiểm tra tính hợp lệ của số điện thoại
void Validator::validatePhone(const std::string& phone) {
    // Kiểm tra độ dài
    if (phone.length() < 10 || phone.length() > 15) {
        throw PhoneException("Phone number must be between 10 and 15 digits.");
    }

    // Kiểm tra xem tất cả các ký tự có phải là số không
    for (char c : phone) {
        if (!std::isdigit(c)) {
            throw PhoneException("Phone number must contain only digits.");
        }
    }

    // Kiểm tra quy tắc số điện thoại ở Việt Nam
    // Số điện thoại Việt Nam thường bắt đầu bằng 0 và có độ dài 10 ký tự (chưa tính mã vùng)
    // Nếu có mã vùng quốc tế (+84), thì bỏ qua ký tự đầu tiên
    if (phone.substr(0, 3) == "+84") {
        if (phone.length() != 13) { // 3 ký tự cho +84 và 10 ký tự cho số điện thoại
            throw PhoneException("Phone number with country code must be 13 characters long.");
        }
    } else if (phone[0] != '0') {
        throw PhoneException("Phone number must start with '0'.");
    }
    else if (phone.length() != 10) { // Nếu không có mã vùng, phải 10 ký tự
        throw PhoneException("Phone number must be 10 digits long without country code.");
    }
}

// Kiểm tra tính hợp lệ của email
void Validator::validateEmail(const std::string& email) {
    // Kiểm tra định dạng email bằng regex
    const std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    if (!std::regex_match(email, emailRegex)) {
        throw EmailException("Invalid email format!");
    }

    // Số lượng ký tự trước và sau ký tự '@'
    size_t atPos = email.find('@');
    std::string localPart = email.substr(0, atPos);
    std::string domainPart = email.substr(atPos + 1);

    // Kiểm tra xem local part và domain part có rỗng không
    if (localPart.empty() || domainPart.empty()) {
        throw EmailException("Email must have a local part and a domain part.");
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

void Validator::validateDate(const std::string& date) {
    // Kiểm tra định dạng và ký tự hợp lệ
    if (date.empty() || (date.find_first_not_of("0123456789-/") != std::string::npos)) {
        throw DateException("Invalid date format! Only digits, '-' and '/' are allowed.");
    }

    // Thay thế '/' bằng '-' để đồng nhất
    std::string normalizedDate = date;
    std::replace(normalizedDate.begin(), normalizedDate.end(), '/', '-');

    // Kiểm tra định dạng ngày sinh
    std::stringstream ss(normalizedDate);
    std::string yearStr, monthStr, dayStr;

    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr);

    // Kiểm tra độ dài
    if (yearStr.length() > 4 || monthStr.length() > 2 || dayStr.length() > 2) {
        throw DateException("Invalid date components length!");
    }

    // Chuyển đổi sang kiểu int
    int year = std::stoi(yearStr);
    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);

    // Kiểm tra năm
    if (year <= 1900) {
        throw DateException("Year must be greater than 1900");
    }

    // Kiểm tra tháng
    if (month < 1 || month > 12) {
        throw DateException("Month must be between 1 and 12.");
    }

    // Kiểm tra ngày hợp lệ theo tháng
    if (day < 1 || day > 31) {
        throw DateException("Day must be between 1 and 31.");
    }

    // Kiểm tra số ngày hợp lệ trong tháng
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw DateException("Invalid day for the given month.");
    }

    // Kiểm tra tháng 2
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2) {
        if (isLeapYear && day > 29) {
            throw DateException("Invalid day for February in a leap year.");
        } else if (!isLeapYear && day > 28) {
            throw DateException("Invalid day for February in a non-leap year.");
        }
    }  
}