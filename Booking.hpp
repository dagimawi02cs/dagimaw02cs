// booking.h
#ifndef BOOKING_H
#define BOOKING_H

#include <string>
using namespace std;

class Booking {
private:
    int bookingID;
    string bookingDate;
    int duration;

public:
    Booking(int id, const string& date, int dur)
        : bookingID(id), bookingDate(date), duration(dur) {}

    int getBookingID() const
    {
        return bookingID;
    }

    const string& getBookingDate() const
    {
        return bookingDate;
    }

    int getDuration() const
    {
        return duration;
    }

    void setBookingDate(const string& date)
    {
        bookingDate = date;
    }

    void setDuration(int dur)
    {
        duration = dur;
    }
};

#endif // BOOKING_H
