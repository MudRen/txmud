// summon.c.
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

varargs private void do_summon(object me,object ob,string str);

int main(object me, string str)
{
	object ob;

	if (!str)
		return notify_fail("<Syntax>: Summon <player id>\n");

	ob = LOGIN_D->find_body(str);
	if(!ob)
		return notify_fail(sprintf("Ŀǰ��Ϸ��û�� %s ����˴��ڡ�\n",str));

#ifdef WIZARD_FLAG
	if(environment(me)->query_wiz_flag()
	&& !wizardp(ob))
		return notify_fail("�㲻�ܽ����ץ���������\n");
#endif

	if(!wizardp(ob))
	{
		write(HIR"\n��ע�⣺�ı���ҵĵ�ǰλ����Υ����ʦ�������Ϊ����
��������Ϊ�ᱻ��¼�ڰ�����˵��������ɣ�\n"NOR);
		me->edit( (: do_summon , me, ob :) );
		return 1;
	}

	else
		do_summon(me,ob);

	return 1;
}

varargs private void do_summon(object me,object ob,string str)
{
	object obj;

        if( (ob != me) && !wizardp(ob) )
                sys_log("summon",sprintf("(%s) summon (%s) from (%s) to (%s).\n%s",
                        geteuid(me),geteuid(ob),(environment(ob))?
			file_name(environment(ob)):"no environment",
                        file_name(environment(me)),"\t"+str ));

	if(file_name(environment(me)) == PRISON_OB
	&& !wizardp(ob)
	&& file_name(environment(ob)) != PRISON_OB)
		log_file("prison",sprintf("%s �� %s(%s) ץ������. %s\n",
			geteuid(me),ob->name(),geteuid(ob),ctime(time())));

	else if(file_name(environment(ob)) == PRISON_OB
	&& !wizardp(ob)
	&& file_name(environment(me)) != PRISON_OB)
		log_file("prison",sprintf("%s �� %s(%s) �Ӽ������ͷ�. %s\n",
			geteuid(me),ob->name(),geteuid(ob),ctime(time())));

	if( obj=ob->query_temp("on_rided") )
	{
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"�������"+obj->name()+"һ��ץ������, Ȼ�᲻����.\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
	environment(ob)->refresh_guarding(ob); // by Find.
	ob->move(environment(me));
	obj->move(environment(me));
	tell_object(me, "���"+(string)ob->query("name")+"�������"+obj->name()+"һ��ץ�������ǰ.\n");
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
	"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"����"+obj->name()+"ͻȻ����"+
	"������ǰ\n",({me,ob}));
	}

	else {
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
	environment(ob)->refresh_guarding(ob); // by Find.
	ob->move(environment(me));
        tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ.\n");
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
	"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ\n",({me,ob}));
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ������㽫ĳ��ץ������ǰ��
HELP
    );
    return 1;
}