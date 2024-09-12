---
layout: page
title: SSH into Build Server
description: Resources
permalink: /useful/ssh_into_build_server
nav_exclude: true
---

# SSH into Build Server

## Mac/Linux
```bash
# username
export UNAME=your_username
# Private key
export PK=/path/to/your/private_key
# Bastion Host
export BH="199.94.60.18"
# Build server; Suranga @ Northeastern U. should have assigned one to you
export BS="192.168.0.XXX"

# -J is ProxyJump -A is
ssh -i ${PK} -J ${UNAME}@${BH} -A ${UNAME}@${BS}
```

### For GUI environment

Create VNC server:
```
$ vncserver -localhost no -geometry 1920x1080
```

> __NOTE__:
> you should only have to use the above command once unless you kill your VNC server

```bash
your_username@fpga-tools:~$ vncserver -localhost no -geometry 1920x1080

You will require a password to access your desktops.

Password:
Verify:
Would you like to enter a view-only password (y/n)? n
/usr/bin/xauth:  file /home/your_username/.Xauthority does not exist

New 'fpga-tools:3 (your_username)' desktop at :3 on machine fpga-tools

Starting applications specified in /etc/X11/Xvnc-session
Log file is /home/your_username/.vnc/fpga-tools:3.log

Use xtigervncviewer -SecurityTypes VncAuth,TLSVnc -passwd /home/your_username/.vnc/passwd fpga-tools:3 to connect to the VNC server.


```

Note the line where it tells you where a desktop is created.
In my case, it was `:3`, so prepend `590` to that for the correct port.


> __NOTE__:
> ~~It's not currently working for me right now.
But GUI not necessary for us for now so feel free to skip this part.~~
> Everything working as expected
```bash
export PORT=5903
#ssh -L $PORT:localhost:5905 -o ProxyCommand="ssh -i <private key> -W %h:%p username@bastion_host" -i <private key> username@build_server
ssh -L ${PORT}:localhost:${PORT} -J ${UNAME}@${BH} -A -i $PK ${UNAME}@${BS}
```
