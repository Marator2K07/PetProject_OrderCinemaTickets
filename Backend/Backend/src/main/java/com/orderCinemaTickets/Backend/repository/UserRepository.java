package com.orderCinemaTickets.Backend.repository;

import com.orderCinemaTickets.Backend.model.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User, Long> {

}
