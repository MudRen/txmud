// zoulang3.c ����3

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
        set("long",@LONG
�������Ӵ��������������ȣ�վ�������ϣ���ֻ��������ϰϰ���細
¶����Զ��������������������˱ǡ��㲻�ɵ�ͣ�½Ų���ϸϸ�������
��լ�����������߾������Ʒ������洫������Ů���ǻ����Ц����
LONG);

	set("outdoors","taxue");

	set("exits",([
		"east" : __DIR__"dating",
		"west" : __DIR__"xiting",
		"north" : __DIR__"xiuyunfang",
	]));
	setup();
	replace_program(ROOM);
}
