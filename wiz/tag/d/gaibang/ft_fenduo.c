// ft_fenduo.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���������������Ĳ��������ؤ�����ֶ����ڡ�ؤ��
һֱ���Ա���������Ϊ�ϰ��������صģ������������ֶ棬Ҳ��
��˵�Ƕ�����˰�����塣��Ҫ���ڷ���������ؤ�����ɲ��
���£��������������ٵĴ�˵��С�����¡�
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "south" : "/d/fengtian/shenwu",
        ]));

        set("objects",([
        __DIR__"npc/ft_duozhu" : 1,
        ]));
 
        setup();
        replace_program(ROOM);
}
