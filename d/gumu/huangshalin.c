
#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "��ɳ��");
        set("long", @LONG
�˴�λ�����ɽ������ֻ��Զ������ԭ�ϣ�������һ����
��ɳ�ѻ����ɵ�ɽ�룬����Ϊ���ء��ݵ�����˵���������̳���
һλ����½���ɵ��ˣ��÷���ǲ��һ�ɻ�ɳ���ɡ�������һƬ
���֡�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "east" : __DIR__"mumen",
        ]));
        setup();
        replace_program(ROOM);
}