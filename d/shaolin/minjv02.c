// Room: /wiz/uudd/path2/minjv02.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ͨ����ӣ�������ʰ�ĺܸɾ����������⻧��
������������������������ȽϺõģ��㿴����û���ˣ���æ��
�˳�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s15",
]));

	setup();
	replace_program(ROOM);
}
