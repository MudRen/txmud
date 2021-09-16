/**************************
 *                        *
 * /adm/daemons/smtp_d.c  *
 *                        *
 * by Find@TX.            *
 *                        *
 **************************/

#include <net/socket.h>
#include <login.h>
#include <ansi.h>
#include <origin.h>

#define RANDOM_PWD_LEN		8 /* ������볤�� */

class email
{
	string rcpt;	// �ռ��ߵ�ַ
	string body;	// ����
	int status;	// ״̬��
	string id;	// �û� ID
	string passwd;	// ����
	object user;
	int normal;
}

protected void write_callback(int fd,string outgoing);
protected varargs void write_callback(int fd,string outgoing);
protected void close_callback(int fd);

protected int mail_have_reg(object user,string mail);
string random_passwd(int len);

protected mixed content = ([]);

protected string mailname = "mud",mailpasswd = "123";
protected string domain_name = "mail.263.net.cn",address = "210.78.128.66";

protected void resolve_callback( string o_address, string resolved, int key )
{
	if( stringp(resolved) && (resolved != "") && (address != resolved) )
	{
		address = resolved;
		log_file("smtp",sprintf("SMTP: Remote SMPT server's ip change to %s\n",address));
	}
}

void update_mail_server_ip()
{
	if(previous_object() && (geteuid(previous_object()) != ROOT_UID))
		return;
	//resolve( domain_name, "resolve_callback" );
}

protected void create()
{
	seteuid(getuid());
	//resolve( domain_name, "resolve_callback" );
}

nomask void send_mail(object user,string mail)
{
	object link;
	string msg,passwd,server,lhalf,rhalf;
	int s,err;
	class email newmail;

#ifndef MAIL_REG
	return;
#endif

	if(!user) return;
	if(!stringp(mail) || mail == "") return;

	mail = lower_case(mail);

        if(!objectp(link = user->query_temp("link_ob")))
	{
		tell_object(user,"���ĵ�������ȫ,�޷�����ע��,�������������ע��.\n\n");
		destruct(user);
		return;
	}

	if( (sscanf(mail,"%s@%s",lhalf,rhalf) != 2)
	|| (lhalf == "")
	|| (rhalf == "") )
	{
                write(sprintf("��ĵ����ʼ���ַ��%s ��ʽ����ȷ��\n�������������ע�ᡣ\n",mail));
                return;
	}

        if(!regexp(mail, "^[a-zA-Z0-9_.@-]+$"))
        {
                write(sprintf("��ĵ����ʼ���ַ��%s ������Ƿ��ַ���\n�������������ע�ᡣ\n",mail));
                return;
        }

	if(mail_have_reg(user,mail))
		return;

	passwd = random_passwd(RANDOM_PWD_LEN);
	server = sprintf("%s 25",address);

	msg = sprintf("From: \"%s\" <%s>\nTo: %s\nSubject: �����ʼ�ȷ�Ϻ�\n\n",
	MUD_NAME,PUBLIC_MUD_MAIL,mail);
	msg += sprintf("��ã���ӭ����"+MUD_NAME+"\n                  ��������������硣\n\n�����˺ţ�%s\n��    �룺%s\n",user->query("id"),passwd);
	msg += "\nע�⣺����˺�ĿǰΪ��ʱ�˺ţ�������48Сʱ֮�ڵ�½ȷ�ϡ�\n";
	msg +=   "      ����δ��½���ᱻ�Զ�ɾ����\n";
	msg +=   "      ����ע���½�������������� "+ PUBLIC_MUD_MAIL+" ��ϵ��\n";
        msg += "\n      ��Ϸ����ҳ�� http://www.mudtx.com/ ��������ϸ�İ���
      �����д������ָ�ϡ�������ܣ����Ż��������ô���

      ע�⣺����Ϊ 8 λ��һλ��ĸ���һλ���֣�
            1,3,5,7 λ����ĸ��2,4,6,8 λ�����֣�
            ���յķ������ÿ�����ճ�����������롣

                 ף���ڡ����¡������죡";

	newmail = new(class email);
	newmail->rcpt = mail;
	newmail->body = msg;
	newmail->id = user->query("id");
	newmail->passwd = passwd;
	newmail->user = user;
	user->start_busy(100);

	s = socket_create(STREAM,"read_callback", "close_callback");
	if(s<0)
	{
		log_file("socket","Socket create err: "+socket_error(s)+"\n");
		tell_object(user,"ע������з�����������������ע��һ�Ρ�\n");
		return;
	}

	content += ([ s : newmail ]);

	err = socket_connect(s,server,"read_callback", "write_call_back");
	if(err<0)
	{
		log_file("socket","Socket connect err: "+socket_error(err)+"\n");
		tell_object(user,"ע������з�����������������ע��һ�Ρ�\n");
		socket_close(s);
		return;
	}

	tell_object(user,"�ʼ������У����Ժ򡣡���������\n");
	call_out("time_out",90,s);
}

protected void time_out(int fd)
{
	class email mailmsg;

	if(undefinedp(content[fd]))
		return;

	mailmsg = content[fd];

	if(objectp(mailmsg->user))
	{
		tell_object(mailmsg->user,"\n���͹��̳�ʱ����������ע��һ�Ρ�\n\n");
		(mailmsg->user)->stop_busy();
	}

	map_delete(content,fd);
	socket_close(fd);
}

protected void success_register(int fd)
{
	class email mailmsg;
	object usr,link;

	if(undefinedp(content[fd]))
		return;

	mailmsg = content[fd];
	if(!objectp(usr = mailmsg->user))
		return;
	if(!objectp(link = usr->query_temp("link_ob")))
		return;

	newbie_reg(mailmsg->id, mailmsg->rcpt);

	usr->stop_busy();

	map_delete(content,fd);

	tell_object(usr,sprintf("\n�����������������Ѹ������Ǽǵĵ�ַ������%s
��������Ӻ����������䡣�������24Сʱ��δ���յ�����
�����������ʼ��������� %s ����˵����ϸ�����
���ǻᾡ��Ϊ�����������֮������½⡣
ף���� %s �����죬�ټ���\n\n\n",mailmsg->rcpt,PUBLIC_MUD_MAIL,MUD_NAME));

	link->set("last_on", time());
	link->set("last_from", query_ip_name(usr));
	link->set("email",mailmsg->rcpt);
	link->set("password",crypt(mailmsg->passwd,0));
	usr->set("email",mailmsg->rcpt);
	usr->set("have_reg",1);
	usr->delete("new_begin");
	link->save();
	usr->save();

	tell_room(environment(usr),"��ֻ������ǰһ����"+usr->query("name")+"�����ˡ�\n",({usr}));
	message("channel:sys",sprintf(HIR"���ʼ�ע�ᾫ�顿��%s(%s)���ע���˳���Ϸ��\n"NOR,
		usr->name(),geteuid(usr)),filter_array(users(),(: wizardp($1) :)));

	destruct(link);
	destruct(usr);
}

protected void close_callback(int fd)
{
	socket_close(fd);
}

protected void mail_error(int fd,string message)
{
	class email mailmsg;

	mailmsg = content[fd];

	log_file("smtp_err",sprintf("ERROR:\n%s\nid: %s\nmail: %s\n\n",
			message,mailmsg->id,mailmsg->rcpt));

	if(objectp(mailmsg->user))
	{
		tell_object(mailmsg->user,sprintf("\n���͹����г����쳣����\n%s\n��������ע��һ�Ρ�\n\n",
			message));
		(mailmsg->user)->stop_busy();
	}

	map_delete(content,fd);
	socket_close(fd);
}

protected void read_callback(int fd,string message)
{
	int rcode,err;
	string mechanism;
	class email mailmsg;

	if(undefinedp(content[fd]))
	{
		socket_close(fd);
		return;
	}

	if(sizeof(message) < 3)
		return;

	mailmsg = content[fd];

	rcode = atoi(message[0..2]);

	if(!rcode || (rcode > 502))
	{
		mail_error(fd,message);
		return;
	}

	if(!mailmsg->status)  // ������ͨ
	{
		socket_write(fd,sprintf("EHLO %s\r\n",query_host_name()));
		mailmsg->status++;
		return;
	}

	if(mailmsg->status == 1) // server ready
	{
		if((rcode == 500) || (rcode == 502))	// command not recognized
		{
			if(mailmsg->normal)
			{
				mail_error(fd,message);
				return;
			}

			socket_write(fd,sprintf("HELO %s\r\n",query_host_name()));
			mailmsg->normal = 1;
			return;
		}

		if(mailmsg->normal)
		{
			// Modified
			//socket_write(fd,sprintf("MAIL FROM: <%s>\r\n",PUBLIC_MUD_MAIL));
			socket_write(fd,sprintf("MAIL FROM: <%s>\r\n","mud@mail.263.net.cn"));

			mailmsg->status = 3;
			return;
		}

		if(sscanf(message,"%*sAUTH=%s\n%*s",mechanism) == 3)
		{
		//	socket_write(fd,sprintf("AUTH %s\r\n",mechanism));
			socket_write(fd,"AUTH LOGIN\r\n");
			mailmsg->status = 2;
			return;
		}

		// ESMTP ����Ҫ��֤
		socket_write(fd,sprintf("MAIL FROM: <%s>\r\n","mud@mail.263.net.cn"));
//		socket_write(fd,sprintf("MAIL FROM: <%s>\r\n",PUBLIC_MUD_MAIL));
		mailmsg->status = 3;
		return;
	}

	if(mailmsg->status == 2)	// Authentication
	{
		string quest;

		if(rcode == 334)	// ��֤����
		{
			quest = message[4..];
			quest = replace_string(quest,"\n","");
			quest = replace_string(quest,"\r","");
			quest = base64_decode(quest);
			if(quest[0..3] == "User")
			{
				socket_write(fd,sprintf("%s\r\n",base64_encode(mailname)));
				return;
			}
			else if(quest[0..3] == "Pass")
			{
				socket_write(fd,sprintf("%s\r\n",base64_encode(mailpasswd)));
				return;
			}
		}

		// ��֤ͨ��
		socket_write(fd,sprintf("MAIL FROM: <%s>\r\n","mud@mail.263.net.cn"));
//		socket_write(fd,sprintf("MAIL FROM: <%s>\r\n",PUBLIC_MUD_MAIL));
		mailmsg->status = 3;
		return;
	}

	if(mailmsg->status == 3)
	{
		socket_write(fd,sprintf("RCPT TO: <%s>\r\n",mailmsg->rcpt));
		mailmsg->status = 4;
		return;
	}

	if(mailmsg->status == 4)
	{
		socket_write(fd,sprintf("DATA\r\n"));
		mailmsg->status = 5;
		return;
	}

	if(mailmsg->status == 5)
	{
		if(rcode == 354)	// ready receive data
		{
			err = socket_write(fd,sprintf("%s\r\n.\r\n",mailmsg->body));
			if( (err < 0) && (err != EEALREADY) )
				call_out("write_callback",1,fd,sprintf("%s\r\n.\r\n",mailmsg->body));
			mailmsg->status = 6;
			return;
		}
		else
		{
			mail_error(fd,message);
			return;
		}
	}

	if(mailmsg->status == 6)
	{
		socket_write(fd,sprintf("QUIT\r\n"));
		mailmsg->status = 7;
		return;
	}

	if((mailmsg->status == 7) && (rcode == 221))
	{
		success_register(fd);
		return;
	}

	mail_error(fd,message);
}

protected varargs void write_callback(int fd,string outgoing)
{
	int err;

	if(stringp(outgoing) && (outgoing != ""))
	{
		err = socket_write(fd,outgoing);

		if( (err < 0) && (err != EEALREADY) )
		{
			call_out("write_callback",1,fd,outgoing);
			return;
		}
	}
}

/* �Ժ�Ҫ�����ĳ�� mail ��ַ�����ƣ�Ҳ������ʵ�֡�*/
protected int mail_have_reg(object user,string mail)
{
	object link;
	string id;

	if(!user) return 1;
	link = user->query_temp("link_ob");
	if(!link) return 1;
	if(!stringp(mail)) return 1;

	id = user->query("id");

	if(!permit_reg_email(mail))
	{
		tell_object(user,"����ʼ���ַ�Ѿ�ע����ˣ�����Ϸ������ͬһ��ַ����ע�ᡣ\n�ټ���\n");
		del_user_data(id,2);
		message("channel:sys",sprintf(HIR"���ʼ�ע�ᾫ�顿��%s(%s)ע�����󱻾ܾ����˳���Ϸ��\n"NOR,
			user->name(),geteuid(user)),filter_array(users(),(: wizardp($1) :)));

		destruct(user);
		destruct(link);
		rm(DATA_DIR + "login/" + id[0..0] + "/" + id + ".o");
		rm(DATA_DIR + "user/"  + id[0..0] + "/" + id + ".o");
		return 1;
	}

	else
		return 0;
}

/* ����48Сʱδ����ȷ��ɾ������ */
void user_no_login()
{
	string *player,time;
	object user,link;

#ifndef MAIL_REG
	return;
#endif

	if(find_object(PAIMING_D) && PAIMING_D->query_is_sorting())
	{
		log_file("smtp","SYSTEM: Is paiming.\n");
			return;
	}

	player = query_exceed_reg_time();
	if(!player || !sizeof(player))
		return;

	time = ctime(time());

	foreach(string one in player)
	{
		string f;

		if(objectp(user = find_player(one)))
		{
			if(objectp(link = user->query("link_ob")))
				destruct(link);
			destruct(user);
		}

		if(file_size(f = sprintf(DATA_DIR+"login/%c/%s.o",one[0],one)) > 0)
			rm(f);
		if(file_size(f = sprintf(DATA_DIR+"user/%c/%s.o",one[0],one)) > 0)
			rm(f);
		log_file("smtp",sprintf("(%s)����48Сʱδ����ȷ�ϱ�ɾ����%s\n",one,time));
	}
}
/*
string random_passwd(int len)
{
	int cap,low,num,n;
	string passwd;
	string Random_Passwd ="ABCDEFGHIJKL1234567890mnopqrstuvwxyzabcdefghi1jkl9MNOPQRS4TUVW9XYZ";

	if(!intp(len))
		return "12345";

	if(len < 4 || len > 8)
		len = 8;

	do
	{
		cap=0; low=0; num=0; passwd = "";
		for(int i=0;i<len;i++)
		{
			n = random(sizeof(Random_Passwd));
			if( Random_Passwd[n] <='Z' && Random_Passwd[n] >='A' )
				cap++;
			else if( Random_Passwd[n] <='z' && Random_Passwd[n] >='a' )
				low++;
			else if( Random_Passwd[n] <='9' && Random_Passwd[n] >='0' )
				num++;
			passwd += Random_Passwd[n..n];
		}
	}
	while(!cap || !low || !num);

	return passwd;
}
*/

string random_passwd(int len)
{
	string letters = "QAZWSXEDCRFVTGBYHNUJMIKLOPpolikujmyhntgbrfvedcwsxqaz";
	string passwd = "";

	if(len < 4 || len > 8)
		len = 8;

	for(int i=0;i<len;i++)
		if(!(i%2))
			passwd += sprintf("%c", letters[random(52)]);
		else
			passwd += sprintf("%d", random(10));

	return passwd;
}
