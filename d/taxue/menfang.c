// menfang.c  �ŷ�
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","̤ѩɽׯ����");
	set("long",
HBBLU+HIR"\n                     ̤ѩɽׯ                           \n\n"NOR
"    ������̤ѩɽׯ�Ĵ��ţ�����������������ͷ��ʯʨ�ӡ������Ϸ���һ\n"
"����ң����顰̤ѩɽׯ���ĸ����֣��ҵ����Ҵ������������������ų�\n"
"���š���ϧ���������������£��������������ڣ��治֪������Ϊʲô����\n"
"������һ���ţ����һ��е�����\n"
);

	set("exits",([
                "enter" : __DIR__"huayuan",
                "south":__DIR__"kongdi",         
	]));

	set("objects",([
		
	]));
	setup();
	replace_program(ROOM);
}
