// Room: /d/hangzhou/zfpath9.c

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
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfpath8",
  "east" : __DIR__"zfwife2",
]));

	setup();
	replace_program(ROOM);
}
