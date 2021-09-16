// treasure.c
#include <ansi.h>
#include <weapon.h>

#ifndef __TREASURE__
#define __TREASURE__

#define TR_ATTRIBUTE    __DIR__"tr_attribute"
#define TR_TYPE                 __DIR__"tr_type"
#define TR_A0T0IN               __DIR__"tr_a0t0in"
#define TR_A0T1IN               __DIR__"tr_a0t1in"
#define TR_A3T0IN               __DIR__"tr_a3t0in"
#define TR_QUERY                __DIR__"tr_query"

//#define TR_SAVE_DIR           DATA_DIR "treasure/"
#define TR_SAVE_DIR             "/wiz/aiai/treasure/save"


#define TR_MAX_DROPS    8       // 最大掉宝数，非人为 = max/2
#define TR_MAX_LEVEL    8       // tr 级别个数
#define TR_GEM                  3       // tr 宝石的属性id
#define TR_CHARM                4       // tr 护符的属性id

#endif

//              set("actions", (: WEAPON_D, "query_action" :) );
///////////////////////////////////////////////////////
// 给tr object增加价值
void tr_add_value(object ob, int val);

// 给tr object定价，由 temp 的 "my_value" 决定
void tr_set_value(object ob, int val);

// 复制tr实例的基本信息
void tr_copy_basic_info(object ob, int attr, int type, int level, int instance);

// 数值随机微调，str格式必须为 "123=456" 
string tr_adjust(string str);

// query attribute mapping
mapping tr_querya(object ob);
// query type mapping
mapping tr_queryt(object ob);
// query level = tr_getl
int tr_queryl(object ob);
// query instance mapping
mapping tr_queryi(object ob);

// 取得tr的信息，供创造 tr 的时候使用
int tr_geta(object ob);
int tr_gett(object ob);
int tr_getl(object ob);
int tr_geti(object ob);

// 给tr object增加价值
void tr_add_value(object ob, int val);

// 查看时的信息
int do_look(string str);

// 生成宝物ob
int tr_make(object ob);

////////////////////////////////////////////////////////////////////////////////
// 下面是一些常用的操作函数

// 给tr object增加价值
void tr_add_value(object ob, int val)
{
        ob->add_temp("my_value", val);
        if ((int)ob->query_temp("my_value", 1)<0)
                ob->set_temp("my_value", 0);
}

// 给tr object定价，由 temp 的 "my_value" 决定
void tr_set_value(object ob, int val)
{
        ob->add_temp("my_value", val);
        if ( !ob->query_temp("my_value") ||
                to_int(ob->query_temp("my_value", 1))<0 )
                ob->set("value", 1);
        else ob->set("value", to_int(ob->query_temp("my_value", 1)));
}

////////////////////////////////////////////////////////////////////////////////
// query attribute mapping
mapping tr_querya(object ob)
{
        return TR_ATTRIBUTE->query((int)ob->query("tr_info/a", 1));
}

// query type mapping
mapping tr_queryt(object ob)
{
        return TR_TYPE->query((int)ob->query("tr_info/a", 1),
                                                  (int)ob->query("tr_info/t", 1));
}

// query level
int tr_queryl(object ob)
{
        return (int)ob->query("tr_info/l", 1);
}

// query instance mapping
mapping tr_queryi(object ob)
{
        int ta, tt;
        mapping ap;

        ta=(int)ob->query("tr_info/a", 1);
        tt=(int)ob->query("tr_info/t", 1);
        switch ( ta )
        {
        case 0:
                switch ( tt )
                {
                case 0:
                        return TR_A0T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                case 1:
                        return TR_A0T1IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                default:        // 先用attr 0 /type 0
                        return TR_A0T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                }
                break;
        case 3:    // 宝石
                switch ( tt )
                {
                case 0:
                        return TR_A3T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                default:
                        return TR_A3T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                }
                break;
        default:
                switch ( tt )
                {
                default:        // 先用attr 0 /type 0
                        return TR_A0T0IN->query((int)ob->query("tr_info/l", 1),
                                                         (int)ob->query("tr_info/i", 1));
                        break;
                }
                break;
        }

        return ap;
}

////////////////////////////////////////////////////////////////////////////////
// 取得tr的信息，供创造 tr 的时候使用
int tr_geta(object ob)
{
        return (int)ob->query_temp("tr_info/a", 1);
}

int tr_gett(object ob)
{
        return (int)ob->query_temp("tr_info/t", 1);
}

int tr_getl(object ob)
{
        return (int)ob->query_temp("tr_info/l", 1);
}

int tr_geti(object ob)
{
        return (int)ob->query("tr_info/i", 1);
}

////////////////////////////////////////////////////////////////////////////////
// 数值随机微调，str格式必须为 "123=456" 
// 100之内用%有可能全是0
// 所以变化幅度用数值 -2 to 2
// >100的数用百分比调整数值
// 变化幅度为 -2% to 2%
string tr_adjust(string str)
{
        int id=0, num=0, tp;
        sscanf(str, "%d=%d", id, num);
        tp=num;
        if (num>-100 && num<100) num+=2-random(5);
        else num+=random(num/25)-num/50;
        if ((tp<0 && num>-1) || (tp>0 && num<1)) tp=num;
        return sprintf("%d=%d", id, num);
}
////////////////////////////////////////////////////////////////////////////////
// 设置武器伤害
//varargs void tr_set_damage(int damage, object ob)
void tr_set_damage(object ob, int damage)
{
        ob->set("weapon_prop/damage", damage);
}

////////////////////////////////////////////////////////////////////////////////
// 判断player是否满足装备/使用限制条件
int tr_on_limit(object me, string lim)
{
        int num=0;
        int id, min;
        mapping ap;

        if (!me || living(me)) me=this_player();

        sscanf(lim, "%d=%d", id, min);
        ap=TR_QUERY->query_limit(id);

        if (!ap) return 0;

        switch (ap["type"])
        {
        case 0: num=(int)me->query(ap["id"], 1);        break;
        case 1: num=me->query_str();    break;
        case 2: num=me->query_cor();    break;
        case 3: num=me->query_int();    break;
        case 4: num=me->query_con();    break;
        case 5: num=me->query_kar();    break;
        case 6: num=me->query_per();    break;
        default:        // -1 ( or <0 )
                num=(int)me->query_skill(ap["id"], 1);
                break;
        }

        if (num<min) return 0;

        return 1;
}

////////////////////////////////////////////////////////////////////////////////
// 复制tr实例中的基本名字
void tr_copy_name(object ob)
{
        mapping ap, api;
        ap=tr_queryt(ob);
        api=tr_queryi(ob);
        if (ap["random_id"])
                if (api["id"]!=ap["id/0"])
                        ob->set_name(api["name"], ({api["id"], ap["id/0"]}));
                else ob->set_name(api["name"], ({api["id"]}));
        else if (api["id"]!=ap["id"]) 
                ob->set_name(api["name"], ({api["id"],ap["id"]}));
        else ob->set_name(api["name"], ({api["id"]}));
}

////////////////////////////////////////////////////////////////////////////////
// 恢复tr中的被隐藏的名字
void tr_revert_name(object ob)
{
        mapping ap;//, api;
        string t_name, t_id;
        t_name=ob->query("hide_name");
        t_id=ob->query("hide_id");
        ap=tr_queryt(ob);
        //api=tr_queryi(ob);
        if (ap["random_id"])
                if (t_id!=ap["id/0"])
                        ob->set_name(t_name, ({t_id, ap["id/0"]}));
                else ob->set_name(t_name, ({t_id}));
        else if (t_id!=ap["id"]) 
                ob->set_name(t_name, ({t_id,ap["id"]}));
        else ob->set_name(t_name, ({t_id}));
}

////////////////////////////////////////////////////////////////////////////////
// 复制tr实例中的基本装备/使用限制      必须用 while 取 mapping 中的 mapping
// is_random=1表示可以让数值微妙变化，幅度为 2%
void tr_copy_limit(object ob, int is_random)
{
        int i=0;
        mapping ap=tr_queryi(ob);

        if (ap["limit/0"])
        {
                while ( ap["limit/"+sprintf("%d", i)] )
                {
                        ob->set("gift_limit/"+sprintf("%d",i),
                                is_random ? tr_adjust(ap["limit/"+sprintf("%d",i)]) : 
                                ap["limit/"+sprintf("%d",i)] );
                        i++;
                }
        }
}

////////////////////////////////////////////////////////////////////////////////
// 复制tr实例中的基本附加属性，返回所取到的instance mapping，为了以后追加缀名
mapping tr_copy_gift(object ob, int is_random)
{
        int i=0;
        mapping ap=tr_queryi(ob);

        if (ap["gift/0"])
        {
                while ( ap["gift/"+sprintf("%d", i)] )
                {
                        // 随机属性标志也复制，如果是鉴别的宝物，则最后在生成
                        // 随机属性；如果是未鉴别的宝物，则在鉴别的时候随机生成
                        if (strsrch(ap["gift/"+sprintf("%d", i)], "-1=") != -1)
                                ob->set("gift_apply/"+sprintf("%d",i),
                                        ap["gift/"+sprintf("%d",i)] );
                        else
                                ob->set("gift_apply/"+sprintf("%d",i),
                                        is_random ? tr_adjust(ap["gift/"+sprintf("%d",i)]) : 
                                        ap["gift/"+sprintf("%d",i)] );
                        i++;
                }
        }
        return ap;
}

////////////////////////////////////////////////////////////////////////////////
// 追加一个tr附加属性，返回gift mapping，为了以后追加缀名
// key_word=追加到哪个mapping上，伪装的时候用
// appointed=-1 表示随机选择属性
// appointed>=0 表示指定属性
// is_random 表示是否对默认值随机微调，对已经已经有的属性附加到上面
// "-1=" 标志不会删除，look tr的时候不将"-1="转换为附加属性
// 鉴定时，每次先del ob 的所有gift，用tr_copy_gift()复制基本
//     然后再用此函数进行随机生成
mapping tr_add_gift(object ob, string key_word,
                                        int is_random, int appointed)
{
        int i=0, k=0, n, gift_id;
        string str;
        mapping ap;

        if (appointed>=0) gift_id = appointed;
        else if ((int)ob->query("tr_info/l", 1) > TR_MAX_LEVEL/2)
                gift_id = random(TR_QUERY->query_gift_total());
        else    // 低级别的tr不能随机取到高级属性
                gift_id = to_int(random(TR_QUERY->query_gift_total())/2+1);

        ap=TR_QUERY->query_gift( gift_id );
        //printf(WHT"DEBUG: gift id %d\n"NOR, gift_id);
        //printf(WHT"DEBUG: sizeof ap %d\n"NOR, sizeof(ap));
        sscanf(ap["gift"],"%*s=%d", n); // 取得默认值

        // 无标志
        if (!ob->query(key_word)) 
        {
                ob->set(key_word+"/0", is_random ?
                        tr_adjust(sprintf("%d=%d",gift_id,n))
                        : sprintf("%d=%d",gift_id,n));
        }
        else
        {
                while ( ob->query(key_word+"/"+sprintf("%d", i)) )
                {
                        sscanf(ob->query(key_word+"/"+sprintf("%d", i)), 
                                "%d=%*d", k);
                        if (k==gift_id)
                        {
                                //printf(WHT"DEBUG: same gift is %d\n"NOR, k);
                                sscanf(ob->query(key_word+"/"+sprintf("%d", i)), 
                                "%*d=%d", k);                           
                                n+=k;
                                break;
                        }
                        i++;
                }
                str=tr_adjust(sprintf("%d=%d", gift_id, n));
                ob->set(key_word+"/"+sprintf("%d", i), 
                        is_random ?
                        tr_adjust(sprintf("%d=%d",gift_id,n))
                        : sprintf("%d=%d",gift_id,n));
        }
        
        tr_add_value(ob, (gift_id+1)*
                ((int)ob->query("tr_info/l",1)+1)*
                100+random((gift_id+1)*100));

        return ap;
}

////////////////////////////////////////////////////////////////////////////////
// 根据一个附加属性追加缀名，gift是tr_add_gift()返回的gift mapping
void tr_add_namefix(object ob, mapping gift)
{
        int i=1;
        string str=ob->name(), str_id;
        mapping ap=tr_queryi(ob);
        mapping type=tr_queryt(ob);

        if (gift["pre_prefix"])         // 加前缀
        {
                if (!ap["prefix"]) return;      // instance不允许追加前缀
                else if ((int)ob->query_temp("prefix", 1)>=ap["prefix"])
                        return;         // 超过instance最大缀数
                else if (ob->query_temp("prefix"))      // 已有前缀
                {
                        // 检查临时缀记录里面是否已有同名缀
                        while (ob->query_temp("pre_name/"+sprintf("%d", i)))
                        {
                                if (ob->query_temp("pre_name/"+sprintf("%d", i))
                                        == gift["name"])
                                        return;
                                i++;
                        }
                        if (gift["pre_prefix"]=="none") return;  // 空缀
                        str=gift["name"]+gift["pre_prefix"]+str;
                        str_id=gift["id"]+"_"+ob->query("id");
                }
                else
                {
                        if (gift["pre_surfix"]=="none") return;  // 空缀
                        // 三种随机缀符号
                        if (random(100)<80)
                                str=gift["name"]+gift["pre_surfix"]+str;
                        else if (random(100)>60) str=gift["name"]+"·"+str;
                        // "★"是闪烁的，先试验一下效果
                        //else str=gift["name"]+ESC+"[5m"+"★"+NOR+str;
                        else str=gift["name"]+"★"+str;
                        //else str=gift["name"]+str;
                        // 计算新id, 采用哪种格式，先试验一下
                        // 格式1        abc def sword of xyz
                        // 格式2        abc_def sword_of_xyz
                        // 格式3        abc-def sword-of-xyz    // 这个还不错
                        //str_id=gift["id"]+" "+ob->query("id");
                        str_id=gift["id"]+" "+ob->query("id");
                        //str_id=gift["id"]+"-"+ob->query("id");
                }
                // 重新给tr命名(加上本类型的通用id)
                if (type["random_id"])
                        if (str_id!=type["id/0"])
                                ob->set_name(str, ({str_id, type["id/0"]}));
                        else ob->set_name(str, ({str_id}));
                else if (str_id!=type["id"])
                        ob->set_name(str, ({str_id, type["id"]}));
                else ob->set_name(str, ({str_id}));
                // 写入临时缀
                ob->add_temp("prefix", 1);
                ob->set_temp("pre_name/"+
                        sprintf("%d",(int)ob->query_temp("prefix", 1)),
                        gift["name"]);
        }
        else if (gift["sur_prefix"])    // 加后缀
        {
                if (!ap["surfix"]) return;      // instance不允许追加前缀
                else if ((int)ob->query_temp("surfix", 1)>=ap["surfix"])
                        return;         // 超过instance最大缀数
                else if (ob->query_temp("surfix"))      // 已有后缀
                {
                        // 检查临时缀记录里面是否已有同名缀
                        while (ob->query_temp("sur_name/"+sprintf("%d", i)))
                        {
                                if (ob->query_temp("sur_name/"+sprintf("%d", i))
                                        == gift["name"])
                                        return;
                                i++;
                        }
                        if (gift["sur_surfix"]=="none") return;  // 空缀
                        str=str+gift["sur_surfix"]+gift["name"];
                        str_id=ob->query("id")+"_"+gift["id"];
                }
                else
                {
                        if (gift["sur_prefix"]=="none") return;  // 空缀
                        // 三种随机缀符号
                        if (random(100)<80)
                                str=str+gift["sur_prefix"]+gift["name"];
                        else if (random(100)>60) str=str+"·"+gift["name"];
                        // "★"是闪烁的，先试验一下效果
                        //else str=str+ESC+"[5m"+"★"+NOR+gift["name"];
                        else str=str+"★"+gift["name"];
                        str_id=ob->query("id")+"'s "+gift["id"];
                }
                // 重新给tr命名(加上本类型的通用id)
                if (type["random_id"])
                        if (str_id!=type["id/0"])
                                ob->set_name(str, ({str_id, type["id/0"]}));
                        else ob->set_name(str, ({str_id}));
                else if (str_id!=type["id"])
                        ob->set_name(str, ({str_id, type["id"]}));
                else ob->set_name(str, ({str_id}));
                // 写入临时缀
                ob->add_temp("surfix", 1);
                ob->set_temp("sur_name/"+
                        sprintf("%d",(int)ob->query_temp("surfix", 1)),
                        gift["name"]);
        }
}

////////////////////////////////////////////////////////////////////////////////
// 复制tr的宝石孔洞，实例tr一律没用被镶嵌宝石
void tr_copy_gem(object obj)
{
        int gems,i;
        mapping ap=tr_queryi(obj);

        if (!ap["gems"]) return;        // 无孔

        gems=ap["gems"];
        if (ap["gems"]==-1)     gems=random(3); // max 2 random gems
        if (!ap["gems"]) return;        // 还是无孔
        if (gems) obj->set("tr_info/gems", gems);
        for (i=0;i<gems;i++)
                obj->set("gift_gem/"+sprintf("%d", i)+"/name", "none");
        // 暂时不把孔洞数显示在name上
        //obj->set( "name", ob->name()+"("+sprintf("%d", gems)+")" );
}

////////////////////////////////////////////////////////////////////////////////
// 将宝石放入tr的宝石孔洞，n是宝石id代码
// 返回>=0表示成功返回镶嵌的位置，-1表示没有孔或者已经满了
int tr_insert_gem(object ob, int n)
{
        int i=0;
        //mapping ap=tr_queryi(ob);
        if (!ob->query("tr_info/gems")) return -1;
        while ( ob->query("gift_gem/"+sprintf("%d",i)) )
        {
                if ( (int)ob->query("gift_gem/"+sprintf("%d",i), 1)==-1 )
                {
                        ob->set("gift_gem/"+sprintf("%d", i), n);
                        // 增加相应属性，由tr_add_gift()负责
                        return n;
                }
                i++;
        }
        return -1;      // already full
}

////////////////////////////////////////////////////////////////////////////////
// 0 青色   1 黒白灰色   2 蓝色   3 粉色   4 红色   5 金色   6 暗金   7 绿色
// 根据级别设置颜色，is_random=0表示级别随机-2 to 2
void tr_set_color(object ob, int is_random)
{
        int lv=(int)ob->query("tr_info/l", 1), ta=0, tb;
        string tp, str=ob->query("hide_name");
        mapping ap;

        if (is_random) lv+=2-random(5);
        if (lv>7) lv=7;
        if (lv<0) lv=0;

        ap=tr_queryt(ob);
        if (ap["type"]=="gem")  // 宝石颜色特殊处理
        {
                if (lv<4) tp=ap["color/0"]+str+NOR;
                else tp=ap["color/1"]+str+NOR;
                ob->set("name", tp);
                return;
        }

        // 带有特殊颜色效果的剑，先试验试验吧
        ta=0;
        if (random(100)>82)
        {
                tp=ESC+"[4m";
                tr_add_value(ob, random(1000)+1000);
                ta=1;
        }
        if (random(100)>84)
        {
                if (ta) tp+=ESC+"[5m";
                else tp=ESC+"[5m";
                tr_add_value(ob, random(2000)+2000);
                ta=1;
        }
        if (random(100)>90)
        {
                if (ta) tp+=ESC+"["+sprintf("%d", random(7)+41)+";" ;
                else tp=ESC+"["+sprintf("%d", random(7)+41)+";" ;
                tr_add_value(ob, random(3000)+3000);
                ta=2;
        }
        
        if (!ta) tp=ESC+"[";
        else if (ta==1) tp+=ESC+"[";
        
        tb=ta;
        ta=random(2);

        switch (lv)
        {
        // 青   13m             21m
        case 0: tp = (ta? tp+"21m" : tp+"13m"); break;
        //黒白灰        47;10m  18m             17m             25m;    
        case 1: switch (0)//random(4))
                {
                case 1: tp += "18m"; break;
                case 2: tp += "17m"; break;
                case 3: tp += "25m"; break;
                case 0: 
                        {
                                if (tb!=2)
                                        tp += "47;10m";
                                else
                                        tp += "10m";
                        }
                } break; 
        // 蓝   11m             19m
        case 2: tp = (ta? tp+"19m" : tp+"11m"); break;
        // 粉   15m             23m
        case 3: tp = (ta? tp+"23m" : tp+"15m"); break;
        // 红   14m             22m
        case 4: tp = (ta? tp+"22m" : tp+"14m"); break;
        // 金   24m
        case 5: tp += "24m";    break;
        // 暗金 16m
        case 6: tp += "16m";    break;
        // 绿   20 
        case 7: tp += "20m";    break;
        }
        tp+=str+NOR;
        ob->set("name", tp);
}

////////////////////////////////////////////////////////////////////////////////
// 隐藏未鉴定tr的某些数值
void tr_pretend(object ob)
{
        int i, j, k;
        mapping type, ap;
        string t_name, t_id, t_long, str;
        string ori_name, ori_id;

        //ori_name=ob->name();  // 保存原始name/id
        //ori_id=ob->query("id");
        ori_name=ob->query("hide_name");        // 保存原始name/id
        ori_id=ob->query("hide_id");

        type=tr_queryt(ob);
        i=0;    // 取得随机name
        if (type["random_name"])
        {
                while ( type["name/"+sprintf("%d", i)] ) i++;
                t_name=type["name/"+sprintf("%d", random(i))];
        }
        else t_name=type["name"];
        i=0;    // 取得随机id
        if (type["random_id"])
        {
                while ( type["id/"+sprintf("%d", i)] ) i++;
                t_id=type["id/"+sprintf("%d", random(i))];
        }
        else t_id=type["id"];
        i=0;    // 取得随机long
        while ( type["long/"+sprintf("%d", i)] ) i++;
        t_long=type["long/"+sprintf("%d", random(i))];
        ob->set_name(t_name,({t_id}));
        ob->delete("pretend_gift");             // 删除上次的假gift
        ob->delete_temp("pre_name");
        ob->delete_temp("sur_name");
        ob->delete_temp("prefix");
        ob->delete_temp("surfix");
        for (i=0;i<random(3);i++)       // 随机追加缀名
        {
                ap=TR_QUERY->query_random_namefix(-1);
                tr_add_namefix(ob, ap);
                if (random(10)>6)
                {
                        j=0;
                        while (ob->query("gift_apply/"+sprintf("%d", j)))
                        {
                                if (random(10)>6)       // 从真实属性中抽取一个
                                {
                                        k=0;
                                        while (ob->query("pretend_gift/"+sprintf("%d", k)))
                                                k++;
                                        str=ob->query("gift_apply/"+sprintf("%d", j));
                                        if (strsrch(str,"-1=")==-1)
                                                ob->set("pretend_gift/"+sprintf("%d", k), str);
                                        break;
                                }
                                j++;
                        }
                        if (!j) tr_add_gift(ob, "pretend_gift", 1, -1);
                }
                else
                {
                        tr_add_gift(ob, "pretend_gift", 1, -1);
                }
        }
        //if (!ob->query("hide_name"))
        //{
                ob->set("hide_name", ob->name());       // 保存临时名字
                ob->set("hide_id", ob->query("id"));
        //}
        tr_set_color(ob, 1);    // 未伪名字设置颜色
        ob->set("value", (int)ob->query_temp("my_value", 1)/10+
                random((int)ob->query_temp("my_value", 1)/10));
        // 隐藏name/id/value/damage
        //if (!ob->query("hide_name"))
        //{
                ob->set("hide_name", ori_name);
                ob->set("hide_id", ori_id);
                ob->set("hide_value", (int)ob->query_temp("my_value", 1));
        //}
        if (ob->query("weapon_prop/damage"))
        {
                i=(int)ob->query("weapon_prop/damage", 1);
                ob->set("hide_damage", i);
                tr_set_damage(ob, to_int(random(i/2)+i/2));
        }
        ob->set("long", replace_string(t_long, "ch", ob->name()));
        ob->delete_temp("pre_name");
        ob->delete_temp("sur_name");
        ob->delete_temp("prefix");
        ob->delete_temp("surfix");
        ob->delete_temp("my_value");
}

////////////////////////////////////////////////////////////////////////////////
// 还原未鉴定的tr
void tr_revert(object ob)
{
        //if (ob->query("tr_ident")) return;    // 已经是被鉴别的武器

        ob->set("tr_ident", 1);
        tr_revert_name(ob);             // 恢复名字
        tr_set_color(ob, 0);
        ob->set("value", (int)ob->query("hide_value", 1));
        if (ob->query("weapon_prop/damage"))
        {
                tr_set_damage(ob, (int)ob->query("hide_damage", 1));
        }
        ob->set("long", replace_string(tr_queryi(ob)["long"], "ch", ob->name()));
        ob->delete("pretend_gift");
}

////////////////////////////////////////////////////////////////////////////////
// 复制tr green set的隐藏数值(如果是绿色套装)
void tr_copy_green_set(object ob)
{
        
}

////////////////////////////////////////////////////////////////////////////////
// 复制tr实例中的基本信息       用在前面
void tr_copy_basic_info(object ob, 
                                                int mf_attr, int mf_type, 
                                                int mf_level, int mf_instance)
{
        int i, num;
        mapping ap, type, attr;
        string sname;

        ob->set("tr_info/a", mf_attr);
        ob->set("tr_info/t", mf_type);
        ob->set("tr_info/l", mf_level);
        ob->set("tr_info/i", mf_instance);

        ap=tr_queryi(ob);
        type=tr_queryt(ob);
        attr=tr_querya(ob);

        tr_copy_name(ob);
        ob->set_weight(ap["weight"]);
        tr_add_value(ob, to_int(random(ap["value"])+ap["value"]/2));
        ob->set("tr_ident", ap["ident"]);

        tr_copy_limit(ob,1);
        tr_copy_gift(ob,1);

        if (strsrch(ap["gift/0"], "-1=") != -1)
        {
                sscanf(ap["gift/0"], "-1=%d", num);
                if (num)
                        for (i=0; i<=random(num); i++)
                        {
                                tr_add_namefix(ob, tr_add_gift(ob, "gift_apply", 1, -1));
                        }
        }

        tr_copy_gem(ob);
        tr_copy_green_set(ob);

        if (ob->query("weapon_prop/damage"))
                tr_set_damage(ob, ap["power"]);

        if (ap["autoload"])
                ob->set("tr_info/autoload", ap["autoload"]);

        ob->set("material", ap["material"]);
        ob->set("hide_name", ob->name());
        ob->set("hide_id", ob->query("id"));

        if (ap["sprite"]!=-1)
                ob->set("tr_sprite", ap["sprite"]);

        if (!ap["ident"]) 
        {
                tr_pretend(ob);
        }
        else
        {
                tr_set_color(ob, 0);
                ob->set("value", (int)ob->query_temp("my_value", 1));
                ob->set("long", replace_string(ap["long"], "ch", ob->name()));
                ob->delete_temp("my_value");
                ob->delete_temp("prefix");
                ob->delete_temp("pre_name");
                ob->delete_temp("surifx");
                ob->delete_temp("sur_name");
        }
        if (ob->query("tr_info/autoload"))
        {
                sname=(tr_queryt(ob)["random_id"] ?
                        tr_queryt(ob)["id/0"]:
                        tr_queryt(ob)["id"]);
                ob->set("tr_info/file", 
                        sprintf(TR_SAVE_DIR "%c/%s%d", sname[0], sname, time()));
                ob->save();
        }
}

////////////////////////////////////////////////////////////////////////////////
// 显示tr的属性         is_true 表示是否显示真实属性，否则显示伪属性
void tr_show_gift(object ob, int is_true)
{
        int i=0, id, num, equiped;
        object me=this_player();
        mapping ap, gift;
        string msg, str, str2, tg;

        if (is_true) tg="gift_apply";
        else tg="pretend_gift";

        if (!ob->query(tg))
                if (!ob->query("tr_info")) return;
                else
                {
                        tell_object(me, "这"+ob->query("unit")+
                        ob->name()+"没有附加属性。\n");
                        return;
                }

        ap=tr_queryi(ob);
        tell_object(me, "\n附加属性：\n");
        while ( ob->query(tg+"/"+sprintf("%d", i)) )
        {
                sscanf(ob->query(tg+"/"+sprintf("%d", i)),
                        "%d=%d", id, num);
                if (id!=-1) 
                {
                        gift=TR_QUERY->query_gift(id);
                        // 有自己特殊的属性函数
                        if (strsrch(gift["type"], "uni=")!=-1)  
                        {
                
                        }
                        else
                        {
                                equiped=tr_querya(ob)["need_equip"];
                                sscanf(gift["gift_name"], "%s=%s", str, str2);
                                switch (gift["type"])
                                {
                                case "+temp":
                                        if (equiped==1) msg=CYN"装备后";
                                        else if (equiped==-1) msg=CYN"使用后";
                                        else if (equiped==-2) msg=CYN"镶嵌上之后";
                                        else msg=CYN"携带后";
                                        msg+="临时增加 "+sprintf("%d", num)
                                                + " "+str2+str+NOR;
                                        break;
                                case "-temp":
                                        if (equiped==1) msg=CYN"装备后";
                                        else if (equiped==-1) msg=CYN"使用后";
                                        else if (equiped==-2) msg=CYN"镶嵌上之后";
                                        else msg=CYN"携带后";
                                        msg+="临时减少 "+sprintf("%d", num)
                                                + " "+str2+str+NOR;
                                        break;
                                case "+max":
                                        if (equiped==1) msg=CYN"装备后";
                                        else if (equiped==-1) msg=CYN"使用后";
                                        else if (equiped==-2) msg=CYN"镶嵌上之后";
                                        else msg=CYN"携带后";
                                        msg+="永久增加 "+sprintf("%d", num)
                                                + " "+str2+str+"，自动消失"NOR;
                                        break;
                                case "-max":
                                        if (equiped==1) msg=CYN"装备后";
                                        else if (equiped==-1) msg=CYN"使用后";
                                        else if (equiped==-2) msg=CYN"镶嵌上之后";
                                        else msg=CYN"携带后";
                                        msg+="永久减少 "+sprintf("%d", num)
                                                + " "+str2+str+"，自动消失"NOR;
                                        break;
                                default:
                                        msg=CYN"--- * 装 饰 * ---"NOR;
                                        break;
                                }
                                tell_object(this_player(), "   "+msg+"\n");
                        }
                }
                i++;
        }
}

////////////////////////////////////////////////////////////////////////////////
// 显示tr的装备限制             is_true 表示是否显示真实限制，否则显示伪限制
// 目前只处理 is_true=1
void tr_show_limit(object ob, int is_true)
{
        int i=0, id, num;
        object me=this_player();
        mapping lim;
        string msg, str, tg;

        //if (is_true) tg="gift_limit";
        //else tg="pretend_limit";

        tg="gift_limit";

        if (!ob->query(tg)) return;

        tell_object(me, "\n限制条件：\n");
        
        while ( ob->query(tg+"/"+sprintf("%d", i)) )
        {
                str=ob->query(tg+"/"+sprintf("%d", i));
                sscanf(str, "%d=%d", id, num);
                lim=TR_QUERY->query_limit(id);
                if (tr_on_limit(me, str)) msg=CYN"   ";
                else msg=RED"   ";
                msg+=sprintf("%d",num)+" ";
                if (lim["type"]<=-1) msg+="级";
                else msg+="点";
                msg+=lim["name"];
                tell_object(me, msg+"\n"NOR);
                i++;
        }
}

////////////////////////////////////////////////////////////////////////////////
// 实现tr的属性         flag=1表示实现，=0表示取消
void tr_apply_gift(object ob, int flag)
{
        int i=0, j, id, num, seed=1, max=0;
        object me=this_player();
        mapping gift;
        string aname, tg;

        // 优先执行假的属性，鉴定之后才执行真的属性
        if (ob->query("pretend_gift"))
                tg="pretend_gift";
        else if (ob->query("gift_apply"))
                tg="gift_apply";
        else return;

        if (!flag) seed=-1;     // 取消属性
        //ap=tr_queryi(ob);
        while ( ob->query(tg+"/"+sprintf("%d", i)) )
        {
                sscanf(ob->query(tg+"/"+sprintf("%d", i)),
                        "%d=%d", id, num);
                num=num*seed;
                if (id!=-1) 
                {
                        gift=TR_QUERY->query_gift(id);
                        sscanf(gift["gift"], "%s=%*d", aname);
                        // 有自己特殊的属性函数
                        if (strsrch(gift["type"], "uni=")!=-1)  
                        {
                
                        }
                        else
                        {
                                //equiped=tr_querya(ob)["need_equip"];
                                switch (gift["type"])
                                {
                                case "+temp":
                                        log_file("USAGE", "tr"+ob->short()+"附加属性 "+aname+" "+
                                                sprintf("%d 点 给 %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        //if (equiped==1)
                                                me->add_temp("apply/"+aname, num);
                                        break;
                                case "-temp":
                                        log_file("USAGE", "tr"+ob->short()+"附加属性 "+aname+" "+
                                                sprintf("%d 点 给 %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        //if (equiped==1)
                                                me->add_temp("apply/"+aname, num);
                                        break;
                                case "+max":
                                        log_file("USAGE", "tr"+ob->short()+"附加属性 "+aname+" "+
                                                sprintf("%d 点 给 %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        if (!gift["add_type"])  // 加到基本data上
                                                me->add(aname, num);
                                        else    // 加到skills上
                                        {
                                                me->set_skill(aname,
                                                        (int)me->query_skill(aname, 1)
                                                        +num);
                                                if ((int)me->query_skill(aname, 1)<1)
                                                        me->abandon_skill(aname);
                                        }
                                        //删除此属性，重新排列属性mapping
                                        j=i+1;
                                        while (ob->query(tg+"/"+sprintf("%d", j)))
                                        {
                                                ob->set(tg+"/"+sprintf("%d", j-1)),
                                                        ob->query(tg+"/"+sprintf("%d", j));
                                                j++;
                                        }
                                        ob->delete(tg+"/"+sprintf("%d", j-1));
                                        i--;
                                        max=1;
                                        break;
                                case "-max":
                                        log_file("USAGE", "tr"+ob->short()+"附加属性 "+aname+" "+
                                                sprintf("%d 点 给 %s (%s)\n",
                                                num, me->short(), 
                                                ctime(time())) );
                                        if (gift["add_type"])   // 加到基本data上
                                                me->add(aname, -num);
                                        else    // 加到skills上
                                        {
                                                me->set_skill(aname,
                                                        (int)me->query_skill(aname, 1)
                                                        -num);
                                                if ((int)me->query_skill(aname, 1)<1)
                                                        me->abandon_skill(aname);
                                        }
                                        //删除此属性，重新排列属性mapping
                                        j=i+1;
                                        while (ob->query(tg+"/"+sprintf("%d", j)))
                                        {
                                                ob->set(tg+"/"+sprintf("%d", j-1)),
                                                        ob->query(tg+"/"+sprintf("%d", j));
                                                j++;
                                        }
                                        ob->delete(tg+"/"+sprintf("%d", j-1));
                                        i--;
                                        max=1;
                                        break;
                                default:
                                        //msg=CYN"--- * 装 饰 * ---"NOR;
                                        break;
                                }
                        }
                }
                i++;
        }

        // 有永久属性的，需要save()一次
        if (max)
        {
                if (ob->query("equipped"))
                {
                        ob->delete("equipped");
                        ob->save();
                        ob->set("equipped");
                }
                else ob->save();
        }

        if (!flag) ob->delete("tr_info/apply");
        else ob->set("tr_info/apply", 1);
                
}

////////////////////////////////////////////////////////////////////////////////
// 为tr增加action
int tr_do_look(string str);
int tr_do_recognize(string str);
int tr_do_recgsure(string str);
int tr_do_recglike(string str);

void tr_add_action()
{
        add_action("do_look","look");
    //add_action("do_wield","wield"); 
        //add_action("do_unwield","unwield");
    //add_action("do_wear","wear"); 
        //add_action("do_remove","remove");
    add_action("do_drop","drop"); 
        add_action("tr_do_recognize", "recg");
        add_action("tr_do_recognize", "jianding");
        add_action("tr_do_recgsure", "recgsure");
        add_action("tr_do_recgsure", "jdsure");
        add_action("tr_do_recglike", "recglike");
        add_action("tr_do_recglike", "recglove");
        add_action("tr_do_recglike", "recgwant");
        add_action("tr_do_recglike", "jdlike");
        add_action("tr_do_recglike", "jdlove");
        add_action("tr_do_recglike", "jdwant");
    //add_action("do_auc","auc"); 
    //add_action("do_give","give");
     
}

int tr_do_look(string str)
{  
        int i;
        object me=this_player();
        object ob;//=this_object();
        string msg;

        if (!str) return 0;
        if (str) str = lower_case(str);
        // 未被辨识，或扔在地上，无法看见属性，仅能看见描述
        if ( !(ob = present(str, me)) )  return 0;

        if ( !ob->query("tr_info") ) return 0;

        tell_object(me, ob->query("long"));

        // 显示装备要求, 未鉴定的物品没有装备限制
        if (ob->query("gift_limit") &&
                ob->query("tr_ident") &&
                !ob->query("pretend_gift"))
        {
                tr_show_limit(ob, (int)ob->query("tr_ident",1));
        }

        // 显示装备属性
        if (ob->query("pretend_gift")) tr_show_gift(ob, 0);
        else tr_show_gift(ob, 1);
        //else tr_show_gift(ob, (int)ob->query("tr_ident",1));

        // 显示宝石
        if (ob->query("tr_info/gems"))
        {
                msg=CYN"   ("+chinese_number(ob->query("tr_info/gems",1))+"个宝石孔洞，";
                if (!ob->query("tr_info/gemed"))
                {
                        msg+="无宝石镶嵌)\n";
                }
                else
                {
                        msg+="已经镶嵌"+chinese_number((int)ob->query("gift_gemd",1))+"个宝石)\n";
                        for (i=0; i<(int)ob->query("tr_info/gemed",1); i++)
                        {
                                //msg+=CYN"    "+ob->query("gift_gem/chn_gem"+sprintf("%d",i+1))+CYN" ("+
                                        //ob->query("gift_gem/gem"+sprintf("%d",i+1))+")\n";
                        }
                }
                tell_object(me,msg+NOR);
        }
        
        // 显示是否auto_load
        if (ob->query("tr_info/autoload"))
                tell_object(me, HIG"   <追随所持者，不会自动掉落>\n"NOR);
        else
                tell_object(me, CYN"   <所持者离开时，掉落在地上>\n"NOR);

        return 1;    
}    

int tr_do_recognize(string str)
{  
        int i;
        int exp, pot, skill, tr_lv;
        int chance;
        object ob;
        object me=this_player();
        string msg;

        if (!str) 
        {
                write(@HELP


指令格式 : 
   recg xxx
   jianding xxx

该指令可以帮助你识别未鉴定的物品。

HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);

        if ( !ob = present(str, me) ) 
                return notify_fail("你只能鉴定自己携带的物品。\n");

//        if (!me->query_skill("recognize"))
        if (!me->query_skill("literate"))
                return notify_fail("你还没有鉴定的能力。\n");

        if ( !ob->query("tr_info") )
                return notify_fail("该物品无法鉴定。\n");

        if (ob->query("tr_ident")) 
                return notify_fail("此物品已经被鉴定。\n");

        tr_lv=(int)ob->query("tr_info/l", 1);
//        skill=(int)me->query_skill("recognize", 1);
        skill=(int)me->query_skill("literate", 1);

        exp=5+random(6);        // 消耗exp
        pot=1+random(2);        // 消耗pot

        if (me->query("combat_exp", 1)<exp+10)
                return notify_fail("你的实战经验不够，无法鉴定该物品。\n");

        if (me->query("potential", 1)<pot+1)
                return notify_fail("你的潜能不足，无法鉴定该物品。\n");

        i=ob->query("tr_info/apply");
        if (i)  // 卸载增加属性
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        if (skill<100)  // 100级以前的成功率
        {
                chance=10+skill/10;
                chance+=(int)me->query("kar", 1)/10
                        + (int)me->query("int", 1)/10;
                if (chance>25) chance=25;
        }
        else
        {
                if (skill>300) skill=300;
                chance=20+skill/5;
                chance+=(int)me->query("kar", 1)/10
                        + (int)me->query("int", 1)/10;
                if (chance>61) chance=61;
        }

        if (random(101) < chance)
        {
                tr_revert(ob);
                ob->set("tr_ident", 0);
                ob->set("tr_success", 1);
        }
        else
        {
                ob->set("tr_success", -1);
                tr_pretend(ob);
        }

        tell_object(me, "鉴定完成！\n\n");
        me->add("combat_exp", -exp);
        me->add("potential", -pot);
//    me->improve_skill( "recognize", random(5), 1);
    me->improve_skill( "literate", random(5), 1);

        tr_do_look(ob->query("id"));

        if (tr_lv>3 && random(100)<tr_lv*10)
        {
                switch (tr_lv)
                {
                case 4: msg="\n这个物品的属性较好"; break;
        case 5: msg="\n这个物品的属性很好"; break;
        default : msg=HIG"\n这个物品有极品属性"; break;
                }
                msg+="，值得收藏。\n"NOR;
                write(msg);
        }

        // 防止flood鉴定
        me->start_busy(2);

        // 加上这个会增加硬盘负担，但是对player更人性化一些
        if (ob->query("tr_info/autoload")) ob->save();

        return 1;
} 

int tr_do_recgsure(string str)
{  
        int i;
        int exp, pot, imp, skill, tr_lv;
        object ob;
        object me=this_player();
        string msg;

        if (!str) 
        {
                write(@HELP


指令格式 : 
   recgsure xxx
   jdsure xxx

该指令可以确认你识别未鉴定的物品。
当你认为鉴定的物品是该物品的本来面貌，可以使用这个指令。

HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);

        if ( !ob = present(str, me) ) 
                return notify_fail("你只能确认自己携带的物品。\n");

//        if (!me->query_skill("recognize"))
        if (!me->query_skill("literate"))
                return notify_fail("你还没有鉴定的能力。\n");

        if ( !ob->query("tr_info") )
                return notify_fail("该物品无法鉴定。\n");

        if (ob->query("tr_ident")) 
                return notify_fail("此物品已经被鉴定。\n");

        if (!ob->query("tr_success")) 
                return notify_fail("你还没有鉴定过该物品！\n");

        tr_lv=(int)ob->query("tr_info/l", 1);
//        skill=(int)me->query_skill("recognize", 1);
        skill=(int)me->query_skill("literate", 1);

        i=ob->query("tr_info/apply");
        if (i)  // 卸载增加属性
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        if ((int)ob->query("tr_success", 1)==1)
        {
                ob->set("tr_ident", 1);
                ob->delete("tr_success");
                ob->delete("hide_name");
                ob->delete("hide_id");
                ob->delete("hide_value");
                ob->delete("hide_damage");
                write("
你觉得这个鉴定结果是正确的。
………………………
………………………………………\n"+
HIC "恭喜你，你的鉴定结果是正确的！\n\n" NOR);
                if (skill<100)
                {
                        exp=to_int(500 * (170-skill-tr_lv*10)/170+random(tr_lv)*10);
                        pot=to_int(50 * (170-skill-tr_lv*10)/170+random(tr_lv));
                }
                else
                {
                        if (skill>300) skill=300;
                        exp=to_int(1000 * (370-skill-tr_lv*10)/370
                                +random(tr_lv)*10+random(skill));
                        pot=to_int(200 * (370-skill-tr_lv*10)/370
                                +random(tr_lv)+random(skill/10));
                }
                msg="通过这次物品鉴定，你获得了：\n" WHT;
                msg+="    "+sprintf("%d 点实战经验\n", exp);
                msg+="    "+sprintf("%d 点潜能\n" NOR, pot);
                write(msg);
                i=me->query_skill("literate",1);
                imp=to_int( skill*10 + (i+random(i))/2 );
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->improve_skill( "recognize", imp );
        }
        else    // 失败不增加exp,pot,skill
        {
                write("
你觉得这个鉴定结果是正确的。
…………………
………………………………
好像……结果并非是预期的那样。\n
你损失了一些实战经验和潜能。\n\n");
                exp=10+random(tr_lv);
                pot=1+random(tr_lv/2);
                me->add("combat_exp", -to_int(exp));
                me->add("potential", -to_int(pot));
                if (me->query("combat_exp", 1)<1)
                        me->set("combat_exp", 0);
                if (me->query("potential", 1)<1)
                        me->set("potential", 0);
                // 失败的话不能增加skill，否则是bug...
                //me->improve_skill( "recognize", to_int(imp/2) );
        }

        return 1;
} 

int tr_do_recglike(string str)
{  
        int i;
        int exp, pot, skill, tr_lv;
        object ob;
        object me=this_player();
        string msg;

        if (!str) 
        {
                write(@HELP


指令格式 : 
   recglike xxx
   recglove xxx
   recgwant xxx
   jdlike xxx
   jdlove xxx
   jdwant xxx

该指令表示你承认未鉴定的物品。
当你喜欢未鉴定物品的属性或名字，可以使用这个指令
承认该物品已被鉴定，并且该物品会跟随拥有者，不会
因为拥有者离开而消失。

注意：使用此指令将消耗一定的潜能和实战经验！

HELP
                );
                return 1;
        }

        if (str) str = lower_case(str);

        if ( !ob = present(str, me) ) 
                return notify_fail("你只能确认自己携带的物品。\n");

//        if (!me->query_skill("recognize"))
        if (!me->query_skill("literate"))
                return notify_fail("你还没有鉴定的能力。\n");

        if ( !ob->query("tr_info") )
                return notify_fail("该物品无法鉴定。\n");

        if (ob->query("tr_ident")) 
                return notify_fail("此物品已经被鉴定。\n");

        tr_lv=(int)ob->query("tr_info/l", 1);
//        skill=(int)me->query_skill("recognize", 1);
        skill=(int)me->query_skill("literate", 1);

        exp=to_int(1000 * (70-tr_lv*10)/70+random(tr_lv)*10);
        pot=to_int(100 * (70-tr_lv*10)/70+random(tr_lv));

        if (me->query("combat_exp", 1)<exp+10)
                return notify_fail("你的实战经验不够，强制承认对身体有害！\n");

        if (me->query("potential", 1)<pot+1)
                return notify_fail("你的潜能不足，强制承认会损伤大脑！\n");

        i=ob->query("tr_info/apply");
        if (i)  // 卸载增加属性
    {
                tr_apply_gift(ob, 0);
                if (ob->query("tr_sprite"))
                        ob->set_heart_beat(0);
    }

        // 转换伪gift为真gift
        if ((int)ob->query("tr_success", 1)==-1)
        {
                ob->delete("gift_apply");
                if (ob->query("pretend_gift"))
                {
                        i=0;
                        while (ob->query("pretend_gift/"+sprintf("%d", i)))
                        {
                                ob->set("gift_apply/"+sprintf("%d", i),
                                        ob->query("pretend_gift/"+sprintf("%d", i)));
                                i++;
                        }
                }
        }

        ob->set("tr_ident", 1);
        ob->delete("pretend_gift");
        ob->delete("tr_success");
        ob->delete("hide_name");
        ob->delete("hide_id");
        ob->delete("hide_value");
        ob->delete("hide_damage");

        write("
你喜欢这个物品现在的名字和属性，
于是承认它就是已鉴定物品。\n\n");

        msg="承认这个物品，你消耗了：\n" WHT;
        msg+="    "+sprintf("%d 点实战经验\n", exp);
        msg+="    "+sprintf("%d 点潜能\n\n" NOR, pot);
        write(msg);
        me->add("combat_exp", -exp);
        me->add("potential", -pot);

        if (!ob->query("tr_info/file"))
        {
                ob->set("tr_info/autoload", 1);
                msg=(tr_queryt(ob)["random_id"] ?
                        tr_queryt(ob)["id/0"]:
                        tr_queryt(ob)["id"]);
                ob->set("tr_info/file", 
                        sprintf(TR_SAVE_DIR "%c/%s%d", msg[0], msg, time()));
        }

        ob->save();

        tr_do_look(ob->query("id"));

        return 1;
} 

int tr_chance(object ob)
{
        int seed=1;
        object winner;
        
        if (living(ob))
        {
                if (ob->query_temp("last_damage_from"))
                {
                        winner = ob->query_temp("last_damage_from");
                        seed+=winner->query("kar", 1)*5;
                        seed+=(winner->query_int()+winner->query_cor())/2;
                        if (F_DTIME->query_day_in_month()%7==0)
                                seed+=7*random(F_DTIME->query_day_in_month())+10;
                        seed+=(winner->query("age", 1)-13)*10;
                        seed+=winner->query_temp("apply/magic_find", 1);
                }
                else    // 自然生成
                {
                        seed+=random(300);
                        // 日子是7的整数倍
                        if (F_DTIME->query_day_in_month()%7==0)
                                seed+=7*random(F_DTIME->query_day_in_month())+10;
                }
        }
        else
        {
                seed+=random(300);
                // 日子是7的整数倍
                        if (F_DTIME->query_day_in_month()%7==0)
                                seed+=7*random(F_DTIME->query_day_in_month())+10;
        }

        if (wizardp(this_player()))
                printf(WHT "debug: 掉宝几率：%d\n" NOR, seed);
        if (seed>800) seed=800;
        if (random(1000) < seed) 
                return seed;  // find treasure!

        return 0;       
}

// 生成宝物ob
int tr_make(object ob)
{
        int i, j, num, seed, temp, region;
        int *attr, *type, *level;
        object tr;
        object winner;

        if (wizardp(this_player()))
                printf(WHT "debug: object=%s\n" NOR, ob->short());

        if (!ob || !objectp(ob)) return 0;

        if (!(seed=tr_chance(ob))) return 0;
        //if (living(ob)) seed=random(1000);
                

        // 取得数量
        if (living(ob))
        {
                if (ob->query_temp("last_damage_from"))
                {
                        winner = ob->query_temp("last_damage_from");
                        num=random(seed/100)+1;
                        if (num>TR_MAX_DROPS) 
                                num=TR_MAX_DROPS;
                }
                else
                {
                        num=random(TR_MAX_DROPS/3)+1;
                }
        }
        else
        {
                num=random(TR_MAX_DROPS/3)+1;
        }

        if (num<1) num=1;

        num=to_int(num);

        if (wizardp(this_player()))
                printf(WHT "debug: 掉宝总数：%d\n" NOR, num);

        attr=allocate(num);
        type=allocate(num);
        level=allocate(num);

        // 使用区间掉落法计算掉落的宝物
        // 取得属性
        for (i=0; i<num; i++)
        {
                // 取得基本因子
                temp=random(to_int(seed*3/2));
                if (temp>1000) temp=1000;
                if (temp<1) temp=1;
                // 计算attr
                attr[i]=0;      // 至少要=0
                region=0;
                for (j=0; j<TR_ATTRIBUTE->query_total(); j++)
                {
                        if ( temp>=region &&
                                 temp<region+TR_ATTRIBUTE->query(j)["chance"] )
                        {
                                if ( TR_ATTRIBUTE->query(j)["enable"] )
                                        attr[i]=j;
                                break;
                        }
                        region+=TR_ATTRIBUTE->query(j)["chance"];
                }
        }

        // 取得类型
        for (i=0; i<num; i++)
        {
                // 取得基本因子
                temp=random(to_int(seed*3/2));
                if (temp>1000) temp=1000;
                if (temp<1) temp=1;
                // 计算type
                type[i]=0;      // 至少要=0
                region=0;
                for (j=0; j<TR_TYPE->query_total(attr[i]); j++)
                {
                        if ( temp>=region &&
                                 temp<region+TR_TYPE->query(attr[i], j)["chance"] )
                        {
                                // 检测此物品是否开放
                                if ( TR_TYPE->query(attr[i], j)["enable"] )
                                        type[i]=j;
                                break;
                        }
                        region+=TR_TYPE->query(j)["chance"];
                }
        }

        // 取得等级
        for (i=0; i<num; i++)
        {
                // 取得基本因子
                temp=random(to_int(seed*3/2));
                if (temp>1000) temp=1000;
                if (temp<1) temp=1;
                level[i]=to_int((TR_MAX_LEVEL-1)*temp/800);
                if (level[i]>=TR_MAX_LEVEL)
                        level[i]=TR_MAX_LEVEL-1;
                if (level[0]<0)
                        level[0]=0;
        }
        
        for (i=0; i<num; i++)
        {
                // 生成基本属性
                switch (attr[i])
                {
                //case 1:
                //      break;

                default:  // 0
                        switch (type[i])
                        {
                        case 1:
                                tr=new(__DIR__"tr_blade");
                                break;
                        default:  // 0
                                tr=new(__DIR__"tr_sword");
                                break;
                        }
                        break;
                }
                // 实例均为随机生成
                if (wizardp(this_player()))
                {
                        printf(WHT "debug: tr：%d, %d, %d\n" NOR, 
                                attr[i], type[i], level[i]);
                }

                tr_copy_basic_info(tr, 
                        attr[i],type[i],level[i], -1);

                // 移动tr
                if (living(ob) || ob->query_temp("unconcious"))
                {
                        if (random(100)<50)     // 留在身上
                                tr->move(ob);
                        else  // 掉在地上
                        {
                                if (objectp(environment(tr)))
                                {
                                        message_vision("你看见从$N身上掉落了一"
                                                +tr->query("unit")+tr->short()+"。\n", ob);
                                        tr->move(environment(tr));
                                }
                                else tr->move(ob);
                        }
                }
                else
                {
                        message_vision("你似乎看见地上有些什么。\n", this_player());
                        tr->move(ob);
                }
        }

        printf(WHT"DEBUG: this_ob=%s\n"NOR, ob->short());
        return 1;
}

