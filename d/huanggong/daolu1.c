// Room: /d/huanggong/daolu1.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�����ڳ����Ĺ����У����������ţ����߾͵������ţ�����
�Ĺ����У��������ɵĳ��Ƽܹ���һ�������Ĺ��ƣ���ҹ֮���
��Իͣ�ʮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanm",
  "north" : __DIR__"wumen",
]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}