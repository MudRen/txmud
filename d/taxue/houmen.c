// houmen.c
// by dicky

#include <room.h>
inherit ROOM;

void create()
{
	set("short","̤ѩɽׯ����");
	set("long",@LONG
������̤ѩɽׯ�ĺ���ţ������Ϸ���һ����ң����顰̤ѩɽׯ���ĸ���
�֣��ҵ����Ҵ������������������Ž����ţ�������̤ѩɽׯר�ŵĵ��ӿ�
�أ����ں�ɽ��Ұ�ޣ�����û�о�������һ�����ǲ����������롣
LONG);

	set(SAFE_ENV, 1);

	set("exits",([
                "north" : __DIR__"xiaolu",
                "south":__DIR__"shilu6",         
	]));

	set("objects",([
		
	]));

	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me,string dir)
{
        if(dir == "north" || dir == "n")
                return notify_fail("ɽׯ����ͦ��һ��˵������û�о����ر�����ɽׯ���Ӳ�������ȥ����\n\n");
        else
                return ::valid_leave(me,dir);
}
*/
