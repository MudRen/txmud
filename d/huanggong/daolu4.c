// Room: /d/huanggong/daolu4.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
�����ڳ����Ĺ����У��������Ļ�����߾͵�����Ԩ��
�������Ĺ����У��������ɵĳ��Ƽܹ���һ�������Ĺ��ƣ���ҹ
֮��ƻ�Իͣ�ʮ��������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"taihm",
  "east" : __DIR__"daolu5",
  ]));
        set("no_clean_up", 0);
        set("outdoors", "huanggong");

        setup();
        replace_program(ROOM);
}