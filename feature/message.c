// message.c
// Modified by Find.

#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500
#define MAX_LEN		8192

static string *msg_buffer = ({});

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
	string *unblock_c = ({"psell","guanfu","paimai","business"});

	if( query_temp("netdead") )
		return;

	if(sizeof(filter_array(explode(msg,"\n"),(: strlen($1) >= MAX_LEN :) )))
	{
		write("��Ϣ���ȳ�����ޡ�\n");
		return;
	}

#ifdef GB_AND_BIG5
	msg = CONVERT_D->output(msg,this_object());	// added for encode.
#endif

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if(member_array(msgclass,unblock_c) == -1)
				{
					if( !pointerp(ch = query("channels"))
					|| member_array(msgclass, ch)==-1 )
						return;
				}
				if(this_object()->query_temp("entering_world"))
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

	if( in_input(this_object()) || in_edit(this_object()) ) {
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
			msg_buffer += ({ msg });
	}
	else
		receive( msg );
}

void write_prompt()
{
	// added for encode.
	string msg = "[����ʱ�ݴ�ѶϢ]\n" ;
#ifdef GB_AND_BIG5
	msg = CONVERT_D->output(msg,this_object());
#endif
	// end.

	if( sizeof(msg_buffer) ) {
		receive(BOLD+msg+NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
        if(wizardp(this_object()) && query("cwd"))
                write(this_object()->query("cwd")+"> ");
        else
                write("> ");
}

void receive_snoop(string msg)
{
	receive("%" + msg);
}
