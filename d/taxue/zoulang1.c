// zoulang1.c ����1
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
	 ��ò������߳�����ǰ���Ȼ���ʣ�����һ����ΡȻ�������Ǿ�
��̤ѩɽׯ�����ͷ֮һ�ģ�̤ѩɽׯ��ׯ���ճ��칫֮����ֻ��̤ѩɽׯ
�ĵ�����Ӳ������ɳ���˵ء�
LONG);

	set("outdoors","taxue");

	set("exits",([
		"west" : __DIR__"huazhen4",
		"north" : __DIR__"neitang",
	]));
	setup();
	replace_program(ROOM);
}
