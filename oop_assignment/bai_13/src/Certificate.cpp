#include "../inc/Certificate.h"
#include <iostream>

Certificate::Certificate(const std::string& id, const std::string& name, const std::string& rank, const std::string& date)
    : certificateId(id), certificateName(name), certificateRank(rank), certificateDate(date) {}

// Getters
std::string Certificate::getCertificateId() const {
    return certificateId;
}

std::string Certificate::getCertificateName() const {
    return certificateName;
}

std::string Certificate::getCertificateRank() const {
    return certificateRank;
}

std::string Certificate::getCertificateDate() const {
    return certificateDate;
}

// Setters
void Certificate::setCertificateId(const std::string& id) {
    certificateId = id;
}

void Certificate::setCertificateName(const std::string& name) {
    certificateName = name;
}

void Certificate::setCertificateRank(const std::string& rank) {
    certificateRank = rank;
}

void Certificate::setCertificateDate(const std::string& date) {
    certificateDate = date;
}

// Hiển thị thông tin chứng chỉ
void Certificate::showInfo() const {
    std::cout << "Certificate ID: " << certificateId << "\n"
              << "Certificate Name: " << certificateName << "\n"
              << "Certificate Rank: " << certificateRank << "\n"
              << "Certificate Date: " << certificateDate << "\n";
}
