// Room: /d/hangzhou/zfpath8.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ������õ����ȣ������Ͼ����ĵģ�ż�������˵�ͷ��
�������Թ��ŵ����������յ������õģ�͸�������Ĵ������Կ�
������ʢ�����ʻ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zfpath7",
  "east" : __DIR__"zfwife",
  "north" : __DIR__"zfpath9",
]));

	setup();
	replace_program(ROOM);
}
