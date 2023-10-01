#include "Layout.h"
#include "Widget.h"

void Layout::AddWidget(const unsigned int row,
                       const unsigned int col,
                       Widget& widget,
                       const VAlignement vAlignement,
                       const HAlignement hAlignement) {
   Data& data = m_widgets[Point2<unsigned int>(col, row)];
   data.m_upWidget.reset(&widget);
   data.m_vAlignement = vAlignement;
   data.m_hAlignement = hAlignement;
}


bool Layout::IsPreset(const unsigned int row, const unsigned int col) const {
   return m_widgets.contains(Point2<unsigned int>(col, row));
}


const Widget& Layout::GetWidget(const unsigned int row, const unsigned int col) const {
   return *m_widgets.at(Point2<unsigned int>(col, row)).m_upWidget.get();
}


Widget& Layout::GetWidget(const unsigned int row, const unsigned int col) {
   return *m_widgets.at(Point2<unsigned int>(col, row)).m_upWidget.get();
}