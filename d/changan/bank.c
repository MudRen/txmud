// bank  Ǯׯ

#include <ansi.h>

inherit BANK;
void create()
{
	set("short", "����¡Ǯׯ");
        set("long", @LONG
����һ�Һܴ��Ǯׯ�����ڵش�����ĵط������������
��ĺá���˵������ϰ�����Ҳ��һλ�����ˣ���֪ʲôԭ���
������ʾ޿�����ⳤ��������Ǯׯ��һ���ţ��Ϳ���ǽ��
�д�����(sign)����̨���С���������Ц��ӭ�˹�����������
�����򶫾��Ǳ������֡�
LONG
        );
/*
        set("night_long",@LONG
������ǳ��������ĻƼ�Ǯׯ��������������ɲ�������
˵�����Ѿ������ˣ����Ĵ���ʰ���������䣬һ˿������
LONG
);
*/
        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "����¡ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan		ת��
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));
	set("exits", ([
                "east"            : __DIR__"nroad9", ]) );
        setup();
}
/*
void open_close_door(string msg,object user)
{
	object ob = present("huang shengfa",this_object());

	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"���ϰ����һ��ȭ˵������ׯ��ʼӪҵ�ˣ���"+
			RANK_D->query_respect(user)+"��ʲôҪ����ľ���Ը���\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"���ϰ����˵������ׯҪ��Ϣ�ˣ�����ʲôҪ��������������������ɡ�\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
		return;
	}
}
*/
