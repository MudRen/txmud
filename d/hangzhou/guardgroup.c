// Room: /d/hangzhou/guardgroup.c

inherit ROOM;

void create()
{
	set("short", "��Զ�ھִ��ſ�");
	set("long", @LONG
����վ�ں�����Զ�ھֵĴ��ſڣ�����Ĵ��ŵ����������
ɫ�������������צ���������������ŵ�һ������ߵ����ң�
����д�š���Զ�ھ֡��ĸ���ɫ���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guardgroup1",
  "north" : __DIR__"guotaiw1",
]));

	setup();
	replace_program(ROOM);
}
