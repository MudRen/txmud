// Room: /d/huashan/xianguan.c

inherit ROOM;

void create()
{
	set("short", "ͨ�ɹ�");
	set("long", @LONG
������ͨ�ɹۣ���˵������������ڴ����ͨ�ɡ��������
�������ң���˵��ʱ�ʵ۶��گ����ɽ������û�н��ܡ�Ϊ�˶�
�ܻʵ�һگ���룬���������ڻ�ɽһ��Сɽ��������������
����Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"w_daoguan",
  "northwest" : __DIR__"lvzu",
  "southeast" : __DIR__"huixin",
]));
        set("outdoors", "huashan");
        set("objects", ([__DIR__"npc/bird":1 ]));
	setup();
	replace_program(ROOM);
}
