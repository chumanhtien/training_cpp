#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include <string>

class Certificate {
private:
    std::string certificateId;
    std::string certificateName;
    std::string certificateRank;
    std::string certificateDate;

public:
    Certificate(const std::string& id, const std::string& name, const std::string& rank, const std::string& date);

    // getters
    std::string getCertificateId() const;
    std::string getCertificateName() const;
    std::string getCertificateRank() const;
    std::string getCertificateDate() const;

    // setters
    void setCertificateId(const std::string& id);
    void setCertificateName(const std::string& name);
    void setCertificateRank(const std::string& rank);
    void setCertificateDate(const std::string& date);

    void showInfo() const; // Hiển thị thông tin của chứng chỉ
};
#endif
