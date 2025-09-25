# IPv4 Packet Structure (RFC 791)

An IPv4 packet consists of a **header** (minimum 20 bytes, maximum 60 bytes) followed by the **payload** (data from the transport layer, e.g. TCP/UDP).

---

## IPv4 Header Format

```
0      7 8     15 16    23 24    31
+--------+--------+--------+--------+
|Version |  IHL   |Type of Service  |
+--------+--------+--------+--------+
|        Total Length (16 bits)     |
+--------+--------+--------+--------+
|        Identification (16 bits)   |
+--------+--------+--------+--------+
|Flags|   Fragment Offset (13 bits) |
+--------+--------+--------+--------+
| Time To Live | Protocol |Checksum |
+--------+--------+--------+--------+
|       Source Address (32 bits)    |
+--------+--------+--------+--------+
|    Destination Address (32 bits)  |
+--------+--------+--------+--------+
|     Options (if any, variable)    |
+--------+--------+--------+--------+
|              Padding              |
+-----------------------------------+
```

---

## Field Descriptions

* **Version (4 bits):** Always `4` for IPv4.
* **IHL – Internet Header Length (4 bits):** Header size in 32-bit words.

  * Min = 5 (20 bytes).
  * Max = 15 (60 bytes).
* **Type of Service (8 bits):** Now split into **DSCP (6 bits)** + **ECN (2 bits)**.

  * DSCP: Differentiated Services Code Point (QoS marking).
  * ECN: Explicit Congestion Notification.
* **Total Length (16 bits):** Entire packet size (header + payload).

  * Range: 20–65,535 bytes.
* **Identification (16 bits):** Identifies fragments of a packet.
* **Flags (3 bits):**

  * bit 0: Reserved (must be 0).
  * bit 1: DF (Don’t Fragment).
  * bit 2: MF (More Fragments).
* **Fragment Offset (13 bits):** Position of fragment in units of 8-byte blocks.
* **Time To Live (8 bits):** Decremented at each router hop. Prevents infinite loops.
* **Protocol (8 bits):** Indicates payload type (transport protocol).

  * 1 = ICMP
  * 2 = IGMP
  * 6 = TCP
  * 17 = UDP
  * 41 = IPv6 encapsulation
  * 89 = OSPF
  * (full list in IANA registry).
* **Header Checksum (16 bits):** One’s complement of the header’s 16-bit words. Protects only the header, not payload.
* **Source Address (32 bits):** IPv4 source.
* **Destination Address (32 bits):** IPv4 destination.
* **Options (variable, optional):** Rarely used. Examples: security, record route, timestamp, source routing.
  Each option has format:

  ```
  +--------+--------+--------+--------+
  |Type    |Length  | Data (variable) |
  +--------+--------+--------+--------+
  ```

  * **Type:** 1 byte (option kind).
  * **Length:** 1 byte (option size in bytes, including type and length).
  * **Data:** variable, option-specific.

  Common option kinds:

  * `0` – End of Option List (EOL)
  * `1` – No Operation (NOP, used for alignment)
  * `7` – Record Route
  * `68` – Timestamp
  * `131` – Loose Source Routing (LSRR)
  * `137` – Strict Source Routing (SSRR)
  * Others defined in RFCs, rarely used.


* **Padding:** Added to ensure header ends on a 32-bit boundary.

