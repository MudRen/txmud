// Room: /d/path1/cc_tch3.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�����ž�ʦ�뱱������Ĺٵ������Ը��ⷱ����·��
���������������ӵġ����̵ġ����Ŵ󳵵�������ﲻ����·
�߻���һЩС�̷��ڽ������ǳ����֡���ʱ�������������߷�
�۶���������һ·������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch2",
  "north" : __DIR__"cc_tch4",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
