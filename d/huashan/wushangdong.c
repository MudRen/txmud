// Room: /d/huashan/wushangdong.c

inherit ROOM;

void create()
{
	set("short", "���϶�");
	set("long", @LONG
�������ʯ�����Ϳɵ���������ˡ����ϵ�ɽ·�������ͣ�
��Ҫ��û��ʮ�ֵİ��գ����ǲ�Ҫ�������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"jinsuoguan",
  "southdown" : __DIR__"xianzhangya",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
