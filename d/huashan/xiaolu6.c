// Room: /d/huashan/xiaolu6.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ���ּ��С·����һ��������������Ұ�����㡣�ݺ�
�����Ϫˮʱ��ʱ�֣�˭Ҳ��֪�����Ǵ��������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xianzhangya",
  "southdown" : __DIR__"xiaolu5",
  "northwest":"/d/huashan_zx/guange3"
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
