//	/adm/daemons/fingerd.c
// Modified by Find.

#include <net/dns.h>

void create() { seteuid( getuid() ); }

string age_string(int time)
{
        int month, day, hour, min, sec;

        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "m":"") + (day?day + "d":"") + 
		(hour?hour + "h":"") + min + "m";
}

string finger_all()
{
        object *ob;
        string msg;
        int i,j,n,nn;
	mixed groups;

        ob = users();
        msg = "";
        if ( !wizardp(this_player()) )  // player finger
        {
		for(i=0; i<sizeof(ob); i++)
		{
			if( this_player() && !this_player()->visible(ob[i]) )
				continue;
                        // added by Find.
                        if(ob[i]->query_temp("netdead")) continue;
                        if(!environment(ob[i])) continue;
                        // end.
			msg = sprintf("%s%-14s%-14s%-14d\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				ob[i]->query("score"), );
		}

		return "£ " + MUD_NAME + "£\n" +
                "！！！！！！！！！！！！！！！！！！\n"
                + "侖兆          嬖催          蕗李\n" +
                "！！！！！！！！！！！！！！！！！！\n"
                + msg +
                "！！！！！！！！！！！！！！！！！！\n";
        }

	else          // wizard finger
        {
		ob = filter_array(ob,(: environment($1)&&!($1->query_temp("netdead")) :));
		groups = unique_array(ob,(: query_ip_number($1) :));
		n = sizeof(groups);
		for(i=0; i<n; i++)
		{
			nn = sizeof(groups[i]);
			for(j=0;j<nn;j++)
			{
				if( this_player() && !this_player()->visible(ob[i]) )
					continue;
				msg = sprintf("%s%s%-20s%-14s%-10s%-14s%s\n",
                                	msg,j==0?"��":"  ",
					sprintf("%s(%s)",groups[i][j]->query("name"),
					groups[i][j]->query("id")),
                                	age_string( (int)groups[i][j]->query("mud_age")), 
                                	query_idle(groups[i][j]) + "s", query_ip_number(groups[i][j]),
					file_name(environment(groups[i][j])));
			}
                }
		return "£ " + MUD_NAME + "£\n" +
                "！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n"
                + "  嬖催                定槍          窟岐      銭��           了崔\n" +
                "！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n"
                + msg +
                "！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n";
        }
}
        
string finger_user(string name)
{
        object ob, body;
        string msg, mud, at;
        int public_flag;

	// added by find.
        if( sscanf(name, "%s@%s", name, mud)==2 )
	{
                GFINGER_Q->send_gfinger_q(mud, name, this_player(1));
                return "利揃峺綜勧僕狛殻辛嬬俶勣匯乂扮寂��萩不昨。\n";
        }
	// end.

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "短嗤宸倖螺社。\n";

        if ( !this_player() || !wizardp(this_player()) )  // player finger
        {
        
                if( objectp(body = find_player(name)) && geteuid(body)==name )
                {
                        public_flag = body->query("env/public")?1:0;
                }

		else
                {
                        body = LOGIN_D->make_body(ob);
                        if( !body->restore() ) return "短嗤宸倖螺社。\n";
                        public_flag = body->query("env/public")?1:0;
                        destruct(body);
                }               

		if( objectp(body = find_player(name)) && (geteuid(body)==name) )
		{
			if(this_player() && this_player()->visible(body))
			at = sprintf("\n%s朕念屎壓銭�炒弌�\n", body->name(1));
		}

                msg =  sprintf("\n哂猟旗催��  %s\n侖    兆��  %s\n幡�浹伴僑�  %s\n"
			"窮徨喨周��  %s\n%s��  %s\n",
                        ob->query("id"),
                        ob->query("name"),
                        SECURITY_D->get_status(name),
                        (public_flag ||
			(this_player()
			&& this_player()->query("id") == ob->query("id")))?
			ob->query("email"):"********",
			at?"序秘扮寂":"曜竃扮寂",
                        ctime(ob->query("last_on")) );
		if(at)
			msg += at;
        }

	else          // wizard finger
        {
		object user = new(USER_OB);
		seteuid(name);
		export_uid(user);
		seteuid(getuid());
		if(!user->restore())
			destruct(user);

		msg =  sprintf("\n哂猟旗催��\t%s\n侖    兆��\t%s\n幡�浹伴僑�\t%s\n"
                        "窮徨喨周仇峽��\t%s\n彜    蓑��\t%s\n貧肝銭�澣慟沓�\t%s( %s )\n",
                        ob->query("id"),
                        ob->query("name"),
                        SECURITY_D->get_status(name),
                        ob->query("email"),
			!objectp(user)?"涙隈珊圻亀宛":(user->query("new_begin")?"仟鞠秘隆廣過喘薩":(user->query("have_reg")?"厮廣過隆鳩範喘薩":"屎塀廣過喘薩")),
                        ob->query("last_from"),
                        ctime(ob->query("last_on"))
                );

		if(objectp(user))
			destruct(user);

		if( objectp(body = find_player(name)) && geteuid(body)==name )
			msg += sprintf("\n%s朕念屎壓貫 %s 銭�炒弌�\n", body->name(1),
				query_ip_name(body));
        }       
        
        destruct(ob);
        return msg;
}

string finger_wiz(string name)
{
        object ob, body;
        string msg ;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "短嗤宸倖螺社。\n";

        if( objectp(body = find_player(name)) && geteuid(body)==name )
        {
                msg = sprintf("%s. %s", body->query("name"), SECURITY_D->get_status(name) );
                destruct(ob);
                return msg;
        }       
        else
        {
                body = LOGIN_D->make_body(ob);
                if(body)
                {
                if(body->restore())
                        msg = sprintf("%s %s", body->name(1), SECURITY_D->get_status(name) );
                }
                destruct(body);
                destruct(ob);
                return msg;
        }

}

varargs string remote_finger_user(string name, int chinese_flag)
{
        object ob, body;
        string msg;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() )
                return chinese_flag ? "短嗤宸倖螺社。\n" : "No such user.\n";
        if( chinese_flag ) msg =  sprintf(
                "\n哂猟旗催��\t%s\n侖    兆��\t%s\n幡�浹伴僑�\t%s\n"
		"窮徨喨周仇峽��\t%s\n貧肝銭�瀛閏筍�\t%s\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                "********",
                ctime(ob->query("last_on"))
        );
        else msg =  sprintf(
                "\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
                capitalize(ob->query("id")),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        if( objectp(body = find_player(name)) && !(wizardp(body) && body->query("env/invisibility")) )
	{
                        msg += chinese_flag ?
                                ("\n" + ob->query("name") + "朕念屎壓�濾蓮�\n"):
                                ("\n" + capitalize(name) + " is currently connected.\n");
        }

        destruct(ob);
        return msg;
}
/*
private object acquire_login_ob(string id)
{
        object ob;

        if( ob = find_player(id) ) {
                // Check if the player is linkdead
                if( ob->query_temp("link_ob") )
                        return ob->query_temp("link_ob");
        }
        ob = new(LOGIN_OB);
        ob->set("id", id);
        return ob->restore() ? ob : 0;
}
*/
/* string get_killer()
{
        int i;
        string msg;
        object *ob = users();

        msg = "";
        for (i = 0; i < sizeof(ob); i++)
                if ((int)ob[i]->query_condition("killer"))
                        msg += (ob[i]->short() + "\n");
        if (msg == "")
                return "云廓嵶芦措挫。\n";
        else
                return "�嶬擶廠杯�壓而鎮參和繁係��\n\n" + msg;
}
*/
