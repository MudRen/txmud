// Room: /d/huashan/xiaolu5.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ����·�ڣ�̧����ȥ��ȫ�ǴԴԵ����֡�������С·
�ϣ����ߴ���һ����ˮ������������ɽ��С·�����滹��һ��С
·�����ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"xiaolu6",
  "east" : __DIR__"quanshui",
  "southwest" : __DIR__"lin2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
