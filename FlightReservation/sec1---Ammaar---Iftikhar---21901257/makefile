# the compiler: gcc for C program, define as g++ for C++

all: Aircraft.o Flight.o Reservation.o ReservationSystem.o
	g++ -g -Wall Aircraft.o Flight.o Reservation.o ReservationSystem.o main.cpp -o FlightReservation
	
Aircraft.o: Aircraft.cpp
	g++ -c Aircraft.cpp
	
Reservation.o: Reservation.cpp
	g++ -c Reservation.cpp 

Flight.o: Flight.cpp
	g++ -c Flight.cpp 

SystemReservation.o: SystemReservation.cpp
	g++ -c SystemReservation.cpp 