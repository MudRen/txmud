// Room: /d/zuojiacun/e_kou.c

inherit ROOM;

void create()
{
	set("short", "��Ҵ嶫��");
	set("long", @LONG
���������Ҵ��ˣ�ԭ��·�߼��ŵ�һ��·�Ʋ�֪��˭����
�ˡ�һ���ӿ����ݵ���ŢС·����һ����һ��ǳ���������棬��
�в��������⡰�ƹ�ط�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu15",
  "east" : "/d/path1/zjz10",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
