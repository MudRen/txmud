// Room: /wiz/louth/c/chome3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����½�������ң�����ǳ��ļ�ª���ر����۵�������һ��
�񻨴�ľ�������Ϲ��ź�ɴ�廨�ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"chome1",
]));

	setup();
	replace_program(ROOM);
}
