// Room: /u/w/wangs/b/kai41.c

inherit ROOM;

void create()
{
	set("short", "С�Ĺ�");
	set("long", @LONG
�ƿ��ſ�������Ĳ������˽�����һ��ߺ������Ľ�������
��������Ʋ�ȥ������ƹ�谵��ʮ������Χ�ż���С����ϯ��
���������Ƕĵ����ƾţ���ע��������ÿ�˸�ǰ�������϶���
����ʮ����ɢ�����ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai54",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
