// bingqi.c  ������

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "��Ǳ�����");
        set("long", @LONG
��Ǳ��������봨�ֺ����ϵı������ˣ�ǽ�Ϲ����˸�ʽ��
���ı����,�����̵����ϰ����ڹ�̨���濴�飬һ�����������
�Ϸ����飬Ц���е�ӭ��������
LONG
        );

        set("night_long", @LONG
��Ǳ��������봨�ֺ����ϵı������ˣ�ǽ�Ϲ����˸�ʽ��
���ı����,���������Ѿ������ˣ������̵����ϰ����ڹ�̨����
�����ʱ����ʡ�
LONG
        );

       set("exits", ([
		"west" : __DIR__"shilu",
           ]));

	set("no_sleep_room",1);

	set("objects",([
//	__DIR__"npc/xxxx" : 1,
           ]));

        setup();
}

/*void open_close_door(string msg,object user)
{
	object ob = present("xxxx",this_object());

	if(!msg || !user)
		return;
	if( msg == "begain_day")
	{
		if(ob)
			tell_object(user,CYN"xxx"+
			RANK_D->query_respect(user)+"xxx��\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
		return;
	}

	else if( msg == "begain_night")
	{
		if(ob)
			tell_object(user,CYN"xxxxx��λ"+
			RANK_D->query_respect(user)+"�Բ���С�Ŵ����ˣ��������������ɡ�\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
		return;
	}
}
*/