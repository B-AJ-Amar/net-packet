# net-packet

I made this repo to learn more about computer networking.  
The goal is to re-implement **UDP** using raw sockets and to manually handle packet structures according to the specifications.

## Purpose
- Explore how networking works at the protocol level.  
- Build a UDP implementation starting from raw sockets.  
- Understand and implement packet formats from:  
  - [RFC 791 – IPv4](https://www.rfc-editor.org/rfc/rfc791)  
  - [RFC 768 – UDP](https://www.rfc-editor.org/rfc/rfc768)  

## Scope
- Reconstruct the IPv4 packet structure (header + payload).  
- Create and parse UDP packets from raw sockets.  
- Work directly with protocol fields such as headers, flags, lengths, and checksums.  

## Notes
- This project is just for learning purposes ,it is not optimized or made for production use.  
- i will make only IPv4 and UDP for now.
