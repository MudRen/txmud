// Room: /d/huashan/xiaolu7.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ����խ��ɽ��С·��һ����ɽ�£�һ��������Բ�
���񣬾��п��ܵ���ɽȥ�����Ʋ�ʱ�������Ư�����㲻���е�
��Щ���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xiaolu8",
  "southeast" : __DIR__"jinsuoguan",
  "southwest":__DIR__"qitu5",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
