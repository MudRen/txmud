// Room: /d/huanggong/xig2.c

inherit ROOM;

void create()
{
        set("short", "˼����");
        set("long", @LONG
������ǹ�������ľ����ˡ������Ĵ��������ûʣ����Գ�
�ʼҵ����ɡ�һ�Կɰ��Ĳ�˹è�������������֮���Ե�ʮ�ֿ�
����������ĵ������������������΢΢һЦ������ǧ�����ģ�
���㿴��ƮƮ���ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xig1",
 
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}