// kongdi.c
// by dicky

#include <ansi.h>
inherit ROOM;
#include <room.h>
string look_shi();

void create ()
{
  set ("short", "�յ�");
  set ("long",@LONG
������ɽ���ϵ�һƬ�յأ���������������Ұ������ɽ����Զ
�����ܣ��Ѻ��ɫ�������������Զ������������ƽ����ż��
��̤ѩɽׯ�ĵ�������������ϰ�䣬�໥�д����ա��յصı��߾���
̤ѩɽׯ��
LONG);

	set("outdoors", "taxue");

	set("exits", ([ /* sizeof() == 3 */
		"north": __DIR__"menfang",
		"south": __DIR__"yashang",
	]));


	setup();
	replace_program(ROOM);
}
