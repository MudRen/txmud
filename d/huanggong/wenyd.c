// Room: /d/huanggong/wenyd.c

inherit ROOM;

void create()
{
        set("short", "��Ԩ��");
        set("long", @LONG
������ǻʹ��Ĳ�������沢�д���˼�����̴ľ�����
����������˸����鼮��������Ǵ��ڵĽ��أ������˵��ǲ���
���ڵģ��ڴ���������һ�ӽ��������ص�Ѳ�飬��ֹ����֮ͽ
�����롣
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"daolu5",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}