// xiaowu.c С�� 

inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
ʮ�ּ�ª��һ��С�ݣ����Ｘ��ʲôҲû�У�ֻ��һ������
��һ�Ŵ�,����ǽ��ȴ����һ��ʮ�ַ����ĸ���(axe)�����ƺ���
Ȼ������ʲô!
LONG
        );
       set("exits", ([
                "west"              : __DIR__"kongdi",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
