// Room: /d/huashan/qitu2.c / by pian

inherit ROOM;

void create()
{
	set("short", "��;");
	set("long", @LONG
ɽ�ƺͻ�������б�������ߵ�ɽ��¶��ͷ����Ѫ�������к
�������ɽ�塣���ᣬ�Ƶ���ż����һ���Է���ɽ�ּ�һ�֣�
��һ����ɽ�裬����û��ɽ��֮�䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"qitu1",
  "east" : __DIR__"qitu3",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
