#pragma once
#include <iostream>

/*
 * ����������� � ���� ������� ���������
 * � ��������� ��
 */
using ValueType = char;
class UniquePtr {
private:
    ValueType* _ptr;
public:
    //�����������
    UniquePtr();

    //����������� �� ���������
    UniquePtr(ValueType* ptr);

    // ����������� �����������
    UniquePtr(UniquePtr&& o) noexcept;

    // ����������� �����������
    UniquePtr(const UniquePtr& o) = delete;

    // �������� ������������ ����� �����������
    UniquePtr& operator=(UniquePtr&& o) noexcept;

    // �������� ������������ ����� �����������
    UniquePtr& operator=(const UniquePtr& o) = delete;

    // �������� ������������ - ��������� ����� ���������
    // �� �������� ��� ������ ������
    UniquePtr& operator=(ValueType* ptr);

    // ���������� _ptr � nullptr
    // �� ������ ��������� ������ ������ ������!
    void reset();

    // reset + ���������� ������ ���������
    void reset(ValueType* ptr);

    // "������������" ���������
    // ��� �������� ������
    void release();

    // ����������, ������ nullptr ��� ���
    operator bool() const;

    // ���������������
    ValueType& operator*() const;

    // �������� ���������
    ValueType* operator->() const;

    // ���������� ���������
    ValueType* get() const;

    ~UniquePtr();
};