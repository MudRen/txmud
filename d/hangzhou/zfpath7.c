// Room: /d/hangzhou/zfpath7.c

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
  //"west" : __DIR__"zfpath5",
  "west" : __DIR__"zfroom",
  "east" : __DIR__"zfzf",
  "north" : __DIR__"zfpath8",
]));

	setup();
	replace_program(ROOM);
}
