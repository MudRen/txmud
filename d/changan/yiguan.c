// yiguan.c
// by dicky
//�˴�valueΪ�ӳ��������ļ۸�

#include <room.h>
#include <ansi.h>
inherit ROOM;
mapping *paizi=({
([  "name":"�ɶ�",      "id":"cd",    "value":150  ]),
([  "name":"���µ�",    "id":"myd",   "value":90   ]),
([  "name":"�ڷ�կ",    "id":"hfz",   "value":90   ]),
([  "name":"��ɽ��",    "id":"hsp",   "value":90   ]),
([  "name":"������",    "id":"hyc",   "value":80   ]),
([  "name":"���ݳ�",    "id":"hzc",   "value":80   ]),
([  "name":"������",    "id":"sls",   "value":80   ]),
([  "name":"���⸮",    "id":"kff",   "value":70   ]),
([  "name":"����",    "id":"fyg",   "value":70   ]),
([  "name":"����կ",    "id":"pyz",   "value":50   ]),
([  "name":"��ͬ��",    "id":"dtf",   "value":50   ]),
([  "name":"��ˮ��",    "id":"tsz",   "value":50   ]),
([  "name":"�����",    "id":"ftc",   "value":50   ]),
([  "name":"�봨��",    "id":"wcz",   "value":40   ]),
([  "name":"��Ҵ�",    "id":"zjc",   "value":40   ]),
([  "name":"̤ѩɽׯ",  "id":"taxue", "value":20   ]),
});
 
string look_paizi();
int do_go(string);

void create()
{
         set("short",HIC"���"NOR);
         set("long", @LONG
���ǳ�������ݣ�����ܴ���ɢ��һ��������˼��ӵ���ζ����Χͣ��
�ü����󳵣������ͣ��˻���š�һλ�ϳ���ר�Ŵ�����������ȥ��������
���ɣ���һ�����߹��������ҵ���������Ц����æӭ��ǰȥ����ݵ��м��и�
ľ���������Ϲ���һ�����ӣ�paizi����
LONG
   );         
         set("exits",([
              "east" : __DIR__"wroad1",
         ]));

         set("item_desc",([
                "paizi" : (: look_paizi :)     
         ]));

         set("objects", ([
                __DIR__"npc/chefu" : 1,
         ]));

         setup();
}

void init()
{
         add_action("do_go", "qu");
}

string look_paizi()
{
         string str=HIW"\n��Ŀ��\n"NOR;
         int i=sizeof(paizi);
         while (i--) {
            str += chinese_number(16-i)+"��";
            str += "ȥ"+paizi[i]["name"];
            str += "("HIW + paizi[i]["id"] + NOR")";
            str += "��"+paizi[i]["value"] + "\n";
         }
         return str;
}
 
void do_move(object ob, int i)
{
        message_vision(YEL"\n$N��Ǯ�����˳��򣬳�����$N����һ���󳵡�\n\n"NOR,ob);
        ob->move(__DIR__"npc/che");
}

int do_go(string arg)
{
        object ob=this_player();
        int i=sizeof(paizi);
        if (!arg) return notify_fail("��Ҫȥ���\n");
        if (ob->is_busy() || ob->is_fighting())
                return notify_fail("����æ���أ�\n");
        while(i--) {
            if (arg == paizi[i]["id"]){
               switch (player_pay(ob, paizi[i]["value"])) {
                  case 0:
                     return notify_fail("��⵰��ûǮ�ͱ�˳��ˣ��Լ������߰ɣ�\n");
                  case 2:
                     return notify_fail("����Ǯ��û��Ǯ�Ļ�ֻ���Լ������ߡ�\n");
               }
               message_vision(HIG"$N�ڳ����������˵����ȥ֮�ء�\n"NOR, ob);

               ob->start_busy(2);
               ob->set_temp("place", arg);
               call_out("do_move", 3, ob, i);
               return 1;
            }
        }
        return notify_fail("��Ҫȥ���\n");
}

