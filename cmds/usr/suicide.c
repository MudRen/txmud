// suicide.c
// Edit by Hao@ES2    30/04/98
// now suicide -f can delete the user mail.

// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
 	if( !arg )
	{
		write(HIY "���ѣ���ִ�е�����ɱָ�����.\n" NOR );
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("��ɱ��ָ���ʽΪ��suicide -f .\n");

	if(me != this_player(1))
		return 0;

	if(wizardp(me))
		return notify_fail("��ʦ������ɱ�������������뽵����\n");

	write( HIY "��ѡ������Զ��������ɱ��ʽ�������������Ͻ�����Զɾ����\n" NOR
		   HIR "ȷ���Ļ��������������룺" NOR);

	seteuid(getuid());

	input_to("check_password", 1, me, 1);
	return 1;
}

protected void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass,temp_time;
	int loop;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");

	if( crypt(passwd, old_pass)!=old_pass )
	{
		write("�������\n");
		return;
	}

	if(forever)
	{
		tell_object( me,HIR "\n\n������Ҫ��ɱ�ˣ��������ڵĻ�������20������ʹ��quitָ���˳���\n\n\n" NOR);
		for (loop=1;loop<20;loop++)
		{
			if (loop%5==0)
			{
				temp_time = (string) loop;
				call_out("show_message",20-loop,me,temp_time);
			}
		}
		call_out("slow_suicide",20,me);
	}
}

void show_message(object ob,string time)
{
	if(!ob)
		return;
	tell_object(ob, HIR "�㻹�� " + time + " ���ʱ����Ժ�ڡ�\n" NOR);
}

protected int slow_suicide(object me)
{
	object link_ob;
	string id,mailfile;

	if(!me)
		return 0;

	link_ob = me->query_temp("link_ob");

	if( !link_ob ) return 0;

	log_file("suicide",sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	id = geteuid(me);

	mailfile=DATA_DIR+ "mail/" + sprintf("%c",id[0]) + "/" + id + ".o";
	if(file_size(mailfile) >= 0)
		rm(mailfile);

	write("�ðɣ�������:)��\n");

	tell_room(environment(me), me->name() + "��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));

	message("channel:sys", sprintf(HIR"��ϵͳ��%s(%s)��ɱ�ˡ�\n"NOR, me->name(), id),
		filter_array(users(),(: wizardp :)));

	if(environment(me) != find_object("/d/wiz/register"))
	{
		//NEWS_D->add_news_item( sprintf("%s(%s) ʵ���޷�����������Ƶ����磬�����˶����Լ���\n",
		//	me->query("name"),capitalize(id)),"p", 1);
		del_user_data(id,1);
	}
	else
		del_user_data(id,2);

	destruct(me);
	PLAYERHOME_D->delete_player_home(id,2);

	rm( DATA_DIR+ sprintf("login/%c/%s.o",id[0],id) );
	rename(DATA_DIR +sprintf( "user/%c/%s.o",id[0],id),BACKUP_DIR+id+".o");

	return 0;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
 
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ�����.
 
������ʹ�á�
 
HELP
);
        return 1;
}
