// Room: /d/huanggong/nanxd.c

inherit ROOM;

void create()
{
        set("short", "��޹��");
        set("long", @LONG
������ǻ��ϵĽ�ϴ������˵ΤС���ڴ˵���������͵�˻�
�ϵ����ڿ㣬���ݺ���һ��������ר�β���֢��������˴��
���ٺ٣���Ҫ��ҪҲ������򹤣���˵���ڵĴ�������ǰ�ö��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"daolu3",
  ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


