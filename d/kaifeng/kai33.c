// Room: /u/w/wangs/b/kai33.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�⻧�˼Ҿ������ģ�����û��һ���ˣ���վ�����������ҿ�
�˿�������Ļ�ûϨ�������ϰ��ż���ûˢ�����˵�������
�˲ų�ȥ���ã�Ժ����ĹսǴ��ڷ��ż�ֻ���ѵĶ��ų��֣���
��ȴû�п������ӣ���������������������ĳ�ȥ�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai32",
]));

	setup();
	replace_program(ROOM);
}
