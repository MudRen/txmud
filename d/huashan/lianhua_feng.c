// Room: /d/huashan/lianhua_feng.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ѿ������˻�ɽ�����嶥����ʱ�а�����������Ư����Ū
�������ʪ¶¶�ġ�ÿ������һ�ȵĻ�ɽ�۽�����ʱ������Ҳ��
��һЩ�����������ʿ���۽��л�ɽС�ۡ���Ҫ�ǲ�֪�书�Ƿ�
�ﵽһ��������������һ�ԡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"xiaolu4",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
